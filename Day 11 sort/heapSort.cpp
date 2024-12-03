#include <iostream>
#include <vector>
using namespace std;

// 调整堆的结构
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // 初始化最大值为根节点
    int left = 2 * i + 1;    // 左子节点
    int right = 2 * i + 2;   // 右子节点

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点比当前最大值大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，交换并递归调整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐个将堆顶元素移动到数组末尾
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // 将当前堆顶放到数组末尾
        heapify(arr, i, 0);   // 调整剩余堆
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
