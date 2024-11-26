#include <iostream>
#include <cstdlib>  // 包含 rand() 和 srand()
#include <ctime>    // 包含 time() 用于种子生成

using namespace std;

int main() {
    // 设置随机数种子，以使每次运行产生不同的随机数
    srand(time(0));

    // 生成一个随机数
    int randomNumber = rand();
    cout << "生成的随机数: " << randomNumber << endl;

    // 生成 0 到 99 的随机数
    int randomInRange = rand() % 100; // 余数法
    cout << "0 到 99 的随机数: " << randomInRange << endl;

    // 生成 50 到 150 的随机数
    int randomInCustomRange = 50 + rand() % 101; // (150 - 50 + 1)
    cout << "50 到 150 的随机数: " << randomInCustomRange << endl;

    return 0;
}
