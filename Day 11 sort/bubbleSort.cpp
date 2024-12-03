#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // 外层循环控制趟数，共 n-1 趟
    for (int i = 0; i < n - 1; i++) {
        // 内层循环控制每一趟的比较次数
        for (int j = 0; j < n - 1 - i; j++) {
            // 如果当前元素比下一个元素大，交换两者
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
