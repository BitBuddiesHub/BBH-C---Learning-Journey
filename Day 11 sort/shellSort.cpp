#include <iostream>
#include <vector>
using namespace std;

// 希尔排序函数
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // 初始间隔为数组大小的一半，逐步缩小间隔
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从 gap 开始，对每组间隔为 gap 的元素进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // 保存当前元素
            int j = i;
            // 在当前间隔内进行插入排序
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; // 将较大的元素右移
                j -= gap;
            }
            arr[j] = temp; // 插入到正确位置
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    shellSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
