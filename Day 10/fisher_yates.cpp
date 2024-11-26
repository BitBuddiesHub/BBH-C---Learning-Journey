#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));

    // 初始化一个数组
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "原始数组: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 随机打乱数组（Fisher-Yates 洗牌算法）
    for (int i = numbers.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1); // 生成 0 到 i 的随机数
        swap(numbers[i], numbers[j]);
    }

    cout << "打乱后的数组: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
