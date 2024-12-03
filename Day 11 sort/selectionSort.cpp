#include <iostream>
#include <vector>
using namespace std;

// 选择排序函数
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // 外层循环：遍历数组的每个元素作为未排序部分的最小值
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // 假设当前索引为最小值
        // 内层循环：找到未排序部分的最小值
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // 更新最小值索引
            }
        }
        // 将未排序部分的最小值交换到前面
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
