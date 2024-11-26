#include <iostream>
#include <vector> // 使用 std::vector 演示更安全的操作

using namespace std;

int main() {
    // 原始数组的声明和初始化
    int original[5] = {10, 20, 30, 40, 50};
    cout << "原始数组内容: ";
    for (int i = 0; i < 5; ++i) {
        cout << original[i] << " ";
    }
    cout << endl;

    // ----------------- 软复制（Shallow Copy） -----------------
    int* shallowCopy = original; // 软复制，只复制了指针
    shallowCopy[0] = 999;        // 修改软复制数组内容，同时影响原数组

    cout << "软复制后原始数组内容（被修改）: ";
    for (int i = 0; i < 5; ++i) {
        cout << original[i] << " ";
    }
    cout << endl;

    cout << "软复制数组内容: ";
    for (int i = 0; i < 5; ++i) {
        cout << shallowCopy[i] << " ";
    }
    cout << endl;

    // ----------------- 硬复制（Deep Copy） -----------------
    int deepCopy[5]; // 创建一个新数组
    for (int i = 0; i < 5; ++i) {
        deepCopy[i] = original[i]; // 将原始数组的值复制到新数组中
    }

    // 修改硬复制数组内容，不影响原始数组
    deepCopy[1] = 888;

    cout << "硬复制数组内容（独立修改）: ";
    for (int i = 0; i < 5; ++i) {
        cout << deepCopy[i] << " ";
    }
    cout << endl;

    cout << "硬复制后原始数组内容（未修改）: ";
    for (int i = 0; i < 5; ++i) {
        cout << original[i] << " ";
    }
    cout << endl;

    // ----------------- 使用 std::vector -----------------
    vector<int> originalVec = {10, 20, 30, 40, 50};
    vector<int> shallowCopyVec = originalVec; // Vector 默认执行硬复制

    shallowCopyVec[0] = 777; // 修改副本不会影响原始数组

    cout << "使用 std::vector 的原始内容: ";
    for (const auto& val : originalVec) {
        cout << val << " ";
    }
    cout << endl;

    cout << "使用 std::vector 的硬复制内容: ";
    for (const auto& val : shallowCopyVec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}