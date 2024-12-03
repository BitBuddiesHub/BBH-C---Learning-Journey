#include <iostream>
#include <vector>
using namespace std;

// 计数排序函数
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end()); // 找到最大值
    int minElement = *min_element(arr.begin(), arr.end()); // 找到最小值
    int range = maxElement - minElement + 1;              // 计算范围

    vector<int> count(range, 0);  // 计数数组
    vector<int> output(arr.size()); // 输出数组

    // 统计每个元素出现的次数
    for (int num : arr)
        count[num - minElement]++;

    // 累加计数
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // 构造输出数组
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    // 复制回原数组
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
