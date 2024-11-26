#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>
#include <atomic>
#include <csetjmp>
#include <chrono>
#include <mutex>
#include <iomanip>

// 测试配置
const size_t CHUNK_SIZE_MB = 256;     // 每块内存大小 (MB)
const size_t TEST_SIZE_MB = 1024;     // 总测试内存大小 (MB)
const size_t THREAD_COUNT = 8;        // 并发线程数量
const int PATTERN_COUNT = 4;          // 测试模式数量
const size_t MMAP_SIZE = 4 * 1024 * 1024; // mmap 测试大小 (4MB)

// 全局变量
std::atomic<bool> stopThreads(false);
std::vector<uint8_t*> chunks;
std::mutex logMutex;
std::jmp_buf jumpBuffer;

// 捕获段错误的信号处理器
void handleSegFault(int sig) {
    std::lock_guard<std::mutex> guard(logMutex);
    std::cerr << "[ERROR] Caught segmentation fault! Signal: " << sig << std::endl;
    std::longjmp(jumpBuffer, 1); // 跳回安全点
}

// 工具函数：格式化内存大小
std::string formatSize(size_t bytes) {
    const size_t MB = 1024 * 1024;
    return std::to_string(bytes / MB) + " MB";
}

// 工具函数：获取当前时间字符串
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now_c))) {
        return std::string(buffer);
    }
    return "Unknown Time";
}

// 工具函数：生成随机数据
void fillRandomData(uint8_t* buffer, size_t size) {
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<uint8_t> distribution(0, 255);
    for (size_t i = 0; i < size; ++i) {
        buffer[i] = distribution(generator);
    }
}

// 测试 1：非法内存访问
void illegalMemoryAccess() {
    std::cout << "[Illegal Memory Access] Writing to NULL pointer..." << std::endl;
    char* invalidPtr = nullptr;
    *invalidPtr = 'A'; // 触发段错误
}

// 测试 2：越界访问内存
void heapOverflow() {
    size_t chunkSize = CHUNK_SIZE_MB * 1024 * 1024;
    char* buffer = (char*)std::malloc(chunkSize);
    if (!buffer) {
        std::cerr << "[Heap Overflow] Memory allocation failed!" << std::endl;
        return;
    }
    std::cout << "[Heap Overflow] Writing beyond allocated memory..." << std::endl;
    buffer[chunkSize + 1] = 'B'; // 超出范围写入
    std::free(buffer);
}

// 测试 3：mmap 操作测试
void mmapTest() {
    std::cout << "[mmap Test] Allocating memory using mmap..." << std::endl;
    void* region = mmap(nullptr, MMAP_SIZE, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (region == MAP_FAILED) {
        perror("[mmap Test] mmap failed");
        return;
    }
    std::cout << "[mmap Test] Attempting to write to read-only memory..." << std::endl;

    // 修改内存保护，避免直接崩溃
    if (mprotect(region, MMAP_SIZE, PROT_WRITE | PROT_READ) == 0) {
        std::cout << "[mmap Test] Successfully changed memory protection. Writing data..." << std::endl;
        char* ptr = static_cast<char*>(region);
        ptr[0] = 'C'; // 写入数据
    } else {
        perror("[mmap Test] mprotect failed");
    }

    munmap(region, MMAP_SIZE);
}

// 测试 4：内联汇编越界写入
void inlineAssemblyTest() {
    char buffer[10];
    std::cout << "[Inline Assembly] Writing beyond buffer using assembly..." << std::endl;
    asm(
        "movl $0x41414141, (%0)\n" // 写入非法内存
        :
        : "r"(buffer + 20)
    );
}

// 测试 5：多线程并发操作
void threadFunction(int id, size_t chunkSize) {
    uint8_t* buffer = chunks[id];
    for (int pattern = 0; pattern < PATTERN_COUNT; ++pattern) {
        std::lock_guard<std::mutex> guard(logMutex);
        std::cout << "[" << getCurrentTime() << "] [Thread " << id << "] Running test pattern " << pattern + 1 << std::endl;

        if (pattern == 0) {
            std::memset(buffer, 0, chunkSize); // 全 0
        } else if (pattern == 1) {
            std::memset(buffer, 0xFF, chunkSize); // 全 1
        } else if (pattern == 2) {
            fillRandomData(buffer, chunkSize); // 随机数据
        } else if (pattern == 3) {
            for (size_t i = 0; i < chunkSize; ++i) {
                buffer[i] = (i % 2 == 0) ? 0xAA : 0x55; // 交替位模式
            }
        }

        // 模拟越界写入
        buffer[chunkSize + id] = 'D'; // 越界写入
    }
}

// 主测试逻辑
bool runMemoryTests() {
    size_t chunkSizeBytes = CHUNK_SIZE_MB * 1024 * 1024;
    size_t totalChunks = TEST_SIZE_MB / CHUNK_SIZE_MB;

    std::cout << "[Memory Test] Allocating memory..." << std::endl;

    // 分配内存
    for (size_t i = 0; i < totalChunks; ++i) {
        uint8_t* chunk = (uint8_t*)std::malloc(chunkSizeBytes);
        if (!chunk) {
            std::cerr << "[Memory Test] Failed to allocate block " << i + 1 << std::endl;
            return false;
        }
        chunks.push_back(chunk);
        std::cout << "[Memory Test] Allocated block " << i + 1 << " of size " << formatSize(chunkSizeBytes) << std::endl;
    }

    // 多线程运行测试
    std::vector<std::thread> threads;
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(threadFunction, i % totalChunks, chunkSizeBytes);
    }

    // 等待线程完成
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "[Memory Test] Completed. Cleaning up..." << std::endl;

    // 释放内存
    for (auto chunk : chunks) {
        std::free(chunk);
    }

    return true;
}

// 主函数
int main() {
    // 注册信号处理器
    std::signal(SIGSEGV, handleSegFault);

    if (setjmp(jumpBuffer) == 0) {
        illegalMemoryAccess();
    } else {
        std::cerr << "[Illegal Memory Access] Recovered from segmentation fault." << std::endl;
    }

    if (setjmp(jumpBuffer) == 0) {
        heapOverflow();
    } else {
        std::cerr << "[Heap Overflow] Recovered from segmentation fault." << std::endl;
    }

    if (setjmp(jumpBuffer) == 0) {
        mmapTest();
    } else {
        std::cerr << "[mmap Test] Recovered from segmentation fault." << std::endl;
    }

    if (setjmp(jumpBuffer) == 0) {
        inlineAssemblyTest();
    } else {
        std::cerr << "[Inline Assembly] Recovered from segmentation fault." << std::endl;
    }

    if (setjmp(jumpBuffer) == 0) {
        runMemoryTests();
    } else {
        std::cerr << "[Memory Test] Recovered from segmentation fault." << std::endl;
    }

    std::cout << "All tests completed." << std::endl;
    return 0;
}
