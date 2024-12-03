#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

// 桶排序函数
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n); // 创建 n 个桶

    // 将元素分配到桶中
    for (float num : arr) {
        int bucketIndex = n * num; // 根据范围计算桶索引
        buckets[bucketIndex].push_back(num);
    }

    // 对每个桶进行排序
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 合并所有桶中的元素
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    bucketSort(arr);
    for (float num : arr) {
        cout << num << " ";
    }
    return 0;
}
