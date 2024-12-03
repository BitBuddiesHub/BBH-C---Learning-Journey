#include <iostream>
#include <vector>
using namespace std;

// 插入排序函数
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    // 从第二个元素开始，逐个插入
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;
        // 将比 key 大的元素向右移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将 key 插入到正确位置
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
