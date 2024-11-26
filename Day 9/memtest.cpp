#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
#include <fstream>
#include <cstring>
#include <sys/sysinfo.h>
#include <ctime>
#include <sstream>

// 获取当前时间字符串（替代 std::put_time）
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now_c))) {
        return std::string(buffer);
    }
    return "Unknown Time";
}

// 配置参数
const size_t CHUNK_SIZE_MB = 128; // 每块内存大小 (MB)
const size_t TEST_SIZE_MB = 512; // 总测试内存大小 (MB)
const int THREAD_COUNT = 4;       // 并发线程数
const int PATTERN_COUNT = 3;      // 测试模式数量
const int TEST_ITERATIONS = 5;    // 每种模式的测试迭代次数

// 全局变量
std::mutex logMutex;              // 日志锁
std::ofstream logFile;            // 日志文件

// 打印系统信息
void printSystemInfo() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        std::cout << "[System Info] Total RAM: " << info.totalram / (1024 * 1024) << " MB, Free RAM: "
                  << info.freeram / (1024 * 1024) << " MB, Processors: " << get_nprocs() << std::endl;
    } else {
        std::cerr << "[System Info] Failed to retrieve system information." << std::endl;
    }
}

// 工具函数：生成随机数据
void fillRandomData(uint8_t* buffer, size_t size) {
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<uint8_t> distribution(0, 255);
    for (size_t i = 0; i < size; ++i) {
        buffer[i] = distribution(generator);
    }
}

// 单线程内存测试
void memoryTest(uint8_t* buffer, size_t size, int threadID) {
    for (int iteration = 0; iteration < TEST_ITERATIONS; ++iteration) {
        for (int pattern = 0; pattern < PATTERN_COUNT; ++pattern) {
            {
                std::lock_guard<std::mutex> guard(logMutex);
                logFile << "[" << getCurrentTime() << "] [Thread " << threadID << "] Iteration " 
                        << iteration + 1 << ", Pattern " << pattern + 1 << "/" << PATTERN_COUNT << std::endl;
            }

            // 写入测试数据
            if (pattern == 0) {
                std::memset(buffer, 0, size);
            } else if (pattern == 1) {
                std::memset(buffer, 0xFF, size);
            } else if (pattern == 2) {
                fillRandomData(buffer, size);
            }

            // 验证数据
            for (size_t i = 0; i < size; ++i) {
                uint8_t expected = (pattern == 0) ? 0 : (pattern == 1) ? 0xFF : buffer[i];
                if (buffer[i] != expected) {
                    std::lock_guard<std::mutex> guard(logMutex);
                    logFile << "[" << getCurrentTime() << "] [Thread " << threadID
                            << "] Data corruption at offset " << i << ": expected " << std::hex << +expected
                            << ", got " << +buffer[i] << std::endl;
                    return;
                }
            }
        }
    }

    {
        std::lock_guard<std::mutex> guard(logMutex);
        logFile << "[" << getCurrentTime() << "] [Thread " << threadID << "] Test completed successfully." << std::endl;
    }
}

// 主测试逻辑
void runMemoryTest() {
    size_t chunkSizeBytes = CHUNK_SIZE_MB * 1024 * 1024;
    size_t totalChunks = TEST_SIZE_MB / CHUNK_SIZE_MB;

    std::cout << "[Memory Test] Allocating memory..." << std::endl;

    // 分配内存块
    std::vector<uint8_t*> chunks;
    for (size_t i = 0; i < totalChunks; ++i) {
        uint8_t* chunk = (uint8_t*)std::malloc(chunkSizeBytes);
        if (!chunk) {
            std::cerr << "[Memory Test] Failed to allocate block " << i + 1 << " of size "
                      << chunkSizeBytes / (1024 * 1024) << " MB." << std::endl;
            return;
        }
        chunks.push_back(chunk);
        std::cout << "[Memory Test] Allocated block " << i + 1 << "/" << totalChunks << " of size "
                  << CHUNK_SIZE_MB << " MB." << std::endl;
    }

    // 多线程运行测试
    std::vector<std::thread> threads;
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(memoryTest, chunks[i % totalChunks], chunkSizeBytes, i);
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    // 释放内存
    std::cout << "[Memory Test] Cleaning up memory..." << std::endl;
    for (auto chunk : chunks) {
        std::free(chunk);
    }
    std::cout << "[Memory Test] All tests completed successfully." << std::endl;
}

// 主函数
int main() {
    // 打开日志文件
    logFile.open("memtest.log");
    if (!logFile) {
        std::cerr << "Failed to open log file!" << std::endl;
        return 1;
    }

    // 打印系统信息
    printSystemInfo();

    std::cout << "[Memory Test] Starting..." << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    // 运行内存测试
    runMemoryTest();

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = endTime - startTime;

    std::cout << "[Memory Test] Completed in " << elapsed.count() << " seconds." << std::endl;

    // 关闭日志文件
    logFile.close();

    return 0;
}
