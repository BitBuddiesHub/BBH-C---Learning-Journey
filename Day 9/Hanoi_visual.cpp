#include <iostream>
#include <stack>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <fstream>
#include <tuple>
#include <sstream>
#include <condition_variable>
#include <queue>
#include <functional>
#include <atomic>
#include <ctime>
#include <sys/resource.h> // 用于获取内存和 CPU 信息 (POSIX)

using namespace std;
using namespace chrono;

// 定义一个锁，用于线程安全的输出
mutex mtx;

// 线程池支持
class ThreadPool {
public:
    ThreadPool(size_t threads) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this]() {
                while (true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(queue_mutex);
                        condition.wait(lock, [this]() { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template <class F>
    void enqueue(F&& task) {
        {
            unique_lock<mutex> lock(queue_mutex);
            tasks.emplace(forward<F>(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (thread& worker : workers)
            worker.join();
    }

private:
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queue_mutex;
    condition_variable condition;
    bool stop = false;
};

// 全局移动步骤计数器
int stepCounter = 0;

// 日志文件输出
ofstream logFile("hanoi_log.txt");

// 获取当前内存使用 (跨平台处理)
string getMemoryUsage() {
#ifdef _WIN32
    return "Memory usage not supported on Windows.";
#else
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long memory = usage.ru_maxrss; // 内存使用量（KB）
    return "Memory: " + to_string(memory) + " KB";
#endif
}

// 获取当前时间戳（线程安全）
string getCurrentTime() {
    auto now = system_clock::now();
    time_t nowTime = system_clock::to_time_t(now);
    struct tm nowTm;
    localtime_r(&nowTime, &nowTm); // 使用线程安全版本的 localtime
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &nowTm);
    return string(buffer);
}

// 显示线程信息
void showThreadInfo() {
    lock_guard<mutex> lock(mtx);
    cout << "Thread ID: " << this_thread::get_id() << endl;
    logFile << "Thread ID: " << this_thread::get_id() << endl;
}

// 可视化当前柱子状态
void visualize(vector<vector<int>>& towers) {
    lock_guard<mutex> lock(mtx);
    cout << "Current State (Step " << stepCounter << "):\n";
    logFile << "Current State (Step " << stepCounter << "):\n";
    for (size_t i = 0; i < towers.size(); i++) {
        cout << "Tower " << char('A' + i) << ": ";
        logFile << "Tower " << char('A' + i) << ": ";
        for (int disk : towers[i]) {
            cout << disk << " ";
            logFile << disk << " ";
        }
        cout << endl;
        logFile << endl;
    }
    cout << "-----------------------\n";
    logFile << "-----------------------\n";
}

// 移动一个盘子并更新状态
void moveDisk(int disk, char from, char to, vector<vector<int>>& towers) {
    lock_guard<mutex> lock(mtx);
    stepCounter++;
    cout << "Step " << stepCounter << ": Move disk " << disk << " from " << from << " to " << to << endl;
    logFile << "Step " << stepCounter << ": Move disk " << disk << " from " << from << " to " << to << endl;
    towers[to - 'A'].push_back(disk); // 将盘子移动到目标柱
    towers[from - 'A'].pop_back();    // 从起始柱移除盘子
    visualize(towers);

    // 输出内存使用和时间信息
    cout << getMemoryUsage() << endl;
    logFile << getMemoryUsage() << endl;
}

// 多线程递归实现汉诺塔
void hanoiRecursive(int n, char from, char to, char aux, vector<vector<int>>& towers, ThreadPool& pool) {
    if (n == 1) {
        moveDisk(1, from, to, towers);
        return;
    }
    atomic<int> pending_tasks(2);
    condition_variable cv;
    mutex local_mtx;

    pool.enqueue([&]() {
        hanoiRecursive(n - 1, from, aux, to, towers, pool);
        if (--pending_tasks == 0) {
            lock_guard<mutex> lock(local_mtx);
            cv.notify_one();
        }
    });

    pool.enqueue([&]() {
        moveDisk(n, from, to, towers);
        hanoiRecursive(n - 1, aux, to, from, towers, pool);
        if (--pending_tasks == 0) {
            lock_guard<mutex> lock(local_mtx);
            cv.notify_one();
        }
    });

    unique_lock<mutex> lock(local_mtx);
    cv.wait(lock, [&]() { return pending_tasks == 0; });
}

// 使用栈模拟递归
void hanoiIterative(int n, char from, char to, char aux, vector<vector<int>>& towers) {
    stack<tuple<int, char, char, char>> moves; // 定义栈保存状态
    moves.push({n, from, to, aux});            // 初始任务
    while (!moves.empty()) {
        auto [disk, src, dst, temp] = moves.top();
        moves.pop();
        if (disk == 1) {
            moveDisk(1, src, dst, towers);
        } else {
            // 按递归逻辑逆序入栈
            moves.push({disk - 1, temp, dst, src});
            moves.push({1, src, dst, temp});
            moves.push({disk - 1, src, temp, dst});
        }
    }
}

int main() {
    int n, numTowers = 3;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "Enter the number of towers (default is 3): ";
    cin >> numTowers;

    if (numTowers < 3) {
        cerr << "At least 3 towers are required for the Hanoi problem. Exiting." << endl;
        return 1;
    }

    // 初始化日志文件
    if (!logFile.is_open()) {
        cerr << "Failed to open log file!" << endl;
        return 1;
    }

    vector<vector<int>> towers(numTowers);
    for (int i = n; i >= 1; --i) {
        towers[0].push_back(i); // 将所有盘子放到柱子 A
    }

    ThreadPool pool(thread::hardware_concurrency());
    auto startTime = high_resolution_clock::now();

    visualize(towers); // 显示初始状态
    hanoiRecursive(n, 'A', 'C', 'B', towers, pool);

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();

    cout << "Total moves: " << stepCounter << endl;
    cout << "Execution Time: " << duration << " ms" << endl;

    logFile << "Total moves: " << stepCounter << endl;
    logFile << "Execution Time: " << duration << " ms" << endl;

    logFile.close();
    return 0;
}
