#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // 生成 0 到 1 之间的随机浮点数
    double randomFloat = static_cast<double>(rand()) / RAND_MAX; // RAND_MAX 是 rand() 的最大返回值
    cout << "0 到 1 之间的随机浮点数: " << randomFloat << endl;

    // 生成 10.5 到 20.5 之间的随机浮点数
    double randomFloatInRange = 10.5 + (static_cast<double>(rand()) / RAND_MAX) * (20.5 - 10.5);
    cout << "10.5 到 20.5 之间的随机浮点数: " << randomFloatInRange << endl;

    return 0;
}
