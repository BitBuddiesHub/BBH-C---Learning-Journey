#include <iostream>
#include <vector>
using namespace std;

// 分区函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1;       // i 指向比 pivot 小的区域的最后一个元素
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // 交换当前元素到比 pivot 小的区域
        }
    }
    swap(arr[i + 1], arr[high]); // 将 pivot 放到正确位置
    return i + 1; // 返回 pivot 的位置
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取分区点
        quickSort(arr, low, pi - 1);        // 排序左子数组
        quickSort(arr, pi + 1, high);       // 排序右子数组
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
