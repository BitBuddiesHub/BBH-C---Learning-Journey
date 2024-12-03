# 堆排序（Heap Sort）实现与逻辑详解

## 代码

```cpp
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
```

---

## 逻辑分析

### **功能**
堆排序是一种基于二叉堆数据结构的比较排序算法。它通过将数组构造成堆结构，反复提取堆顶元素并调整堆结构完成排序。

---

## 步骤与逻辑

### **1. 构建最大堆**
```cpp
for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
```
- **逻辑**: 从最后一个非叶子节点开始，自下而上调整堆。
- **堆结构**:
  - 堆的父子节点关系:
    - 父节点索引：`i`
    - 左子节点索引：`2 * i + 1`
    - 右子节点索引：`2 * i + 2`

---

### **2. 调整堆结构 (`heapify`)**
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
```
- **逻辑**: 检查当前节点及其左右子节点，找到最大值。如果当前节点不是最大值，交换并递归调整。
- **递归**: 确保交换后的子树依然满足堆性质。

---

### **3. 排序**
```cpp
for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
}
```
- **逻辑**: 将堆顶元素（最大值）与最后一个元素交换，将其放入已排序部分。然后调整剩余的堆以维持最大堆性质。
- 每次交换后，未排序部分长度减 1。

---

## 示例运行过程

初始数组：
```
{4, 10, 3, 5, 1}
```

### **1. 构建最大堆**
堆化过程：
1. 调整节点 `1`（值为 `10`）:
   ```
   {4, 10, 3, 5, 1} -> 最大堆部分
   ```
2. 调整节点 `0`（值为 `4`）:
   ```
   {10, 5, 3, 4, 1}
   ```

**构建完成后的堆**:
```
{10, 5, 3, 4, 1}
```

---

### **2. 排序**
1. 交换堆顶与最后一个元素，调整堆：
   ```
   {1, 5, 3, 4, 10} -> {5, 4, 3, 1, 10}
   ```
2. 交换堆顶与倒数第二个元素，调整堆：
   ```
   {1, 4, 3, 5, 10} -> {4, 1, 3, 5, 10}
   ```
3. 继续交换和调整：
   ```
   {3, 1, 4, 5, 10} -> {1, 3, 4, 5, 10}
   ```

最终输出：
```
{1, 3, 4, 5, 10}
```

---

## 复杂度分析

### 时间复杂度
1. **建堆**:
   - 每个非叶子节点调用 `heapify`，时间复杂度为 \( O(\log n) \)。
   - 总体时间复杂度为 \( O(n) \)。

2. **排序**:
   - 每次提取堆顶元素后调用 `heapify`，时间复杂度为 \( O(\log n) \)。
   - \( n-1 \) 次提取操作，总体时间复杂度为 \( O(n \log n) \)。

**总时间复杂度**: \( O(n \log n) \)。

### 空间复杂度
- 原地排序，无需额外存储空间，空间复杂度为 \( O(1) \)。

---

## 适用场景

1. **数组排序**:
   - 适用于需要原地排序的场景。
2. **不稳定排序**:
   - 堆排序是**不稳定排序**，在某些场景中需要注意。

---

## 优点与缺点

### 优点
- 时间复杂度稳定为 \( O(n \log n) \)。
- 原地排序，不需要额外空间。

### 缺点
- 实现相对复杂。
- 不稳定排序。

---

## 总结

堆排序是一种高效且稳定的排序算法，特别适合大规模数据排序任务。通过最大堆的构建和调整，能够在 \( O(n \log n) \) 时间内完成排序，且无需额外空间。实际应用时，需根据具体场景权衡其优缺点。