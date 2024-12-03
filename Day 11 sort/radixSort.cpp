#include <iostream>
#include <vector>
using namespace std;

// 获取某一位上的数字
int getDigit(int num, int place) {
    return (num / place) % 10;
}

// 基数排序的计数排序步骤
void countingSortForRadix(vector<int>& arr, int place) {
    int n = arr.size();
    vector<int> output(n); // 输出数组
    vector<int> count(10, 0); // 计数数组，范围是 0-9

    // 统计该位上的出现次数
    for (int num : arr)
        count[getDigit(num, place)]++;

    // 累加计数
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 按该位的数字构造输出数组
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], place);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 复制回原数组
    arr = output;
}

// 基数排序函数
void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end()); // 找到最大值

    // 从个位开始，对每一位进行计数排序
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSortForRadix(arr, place);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
