#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // 随机生成一个数组
    const int size = 10; // 数组大小
    int randomArray[size];

    cout << "随机生成的数组: ";
    for (int i = 0; i < size; ++i) {
        randomArray[i] = rand() % 100; // 生成 0 到 99 的随机数
        cout << randomArray[i] << " ";
    }
    cout << endl;

    return 0;
}
