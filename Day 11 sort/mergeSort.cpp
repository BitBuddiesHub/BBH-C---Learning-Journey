#include <iostream>
#include <vector>
using namespace std;

// 合并函数
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // 左子数组大小
    int n2 = right - mid;    // 右子数组大小
    vector<int> L(n1), R(n2); // 创建临时数组
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    // 合并两个子数组
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 复制剩余元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// 归并排序函数
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);       // 排序左半部分
        mergeSort(arr, mid + 1, right); // 排序右半部分
        merge(arr, left, mid, right);   // 合并两部分
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
