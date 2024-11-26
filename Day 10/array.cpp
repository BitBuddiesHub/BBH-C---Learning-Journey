#include <iostream> // 包含输入输出流库，用于控制台输入输出
#include <algorithm> // 包含标准库算法，用于排序等操作
using namespace std;

int main() {
    // 一维数组的声明和初始化
    int arr[5] = {10, 20, 30, 40, 50}; // 声明一个大小为5的整数数组并初始化
    int size = 5; // 保存数组的大小，便于后续操作

    // 输出一维数组的初始值
    cout << "初始数组: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 修改数组中的值
    arr[2] = 100; // 将数组的第三个元素修改为100
    cout << "修改后数组: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 查找数组中的最大值和最小值
    int max_val = *max_element(arr, arr + size); // 使用标准库函数找到最大值
    int min_val = *min_element(arr, arr + size); // 使用标准库函数找到最小值
    cout << "数组的最大值: " << max_val << endl;
    cout << "数组的最小值: " << min_val << endl;

    // 数组的排序
    sort(arr, arr + size); // 升序排序
    cout << "排序后的数组: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 二维数组的声明和初始化
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; // 声明一个3x3的矩阵并初始化
    cout << "二维数组（矩阵）: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 修改二维数组的值
    matrix[1][1] = 100; // 将矩阵的中心值修改为100
    cout << "修改后的二维数组: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 动态数组
    int* dynArr = new int[size]; // 动态分配一个大小为5的一维数组
    for (int i = 0; i < size; ++i) {
        dynArr[i] = i * 10; // 动态数组赋值
    }
    cout << "动态分配的数组: ";
    for (int i = 0; i < size; ++i) {
        cout << dynArr[i] << " ";
    }
    cout << endl;

    // 释放动态数组
    delete[] dynArr; // 释放动态分配的内存
    cout << "动态数组已释放" << endl;

    return 0;
}
