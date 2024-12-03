# 快速排序（Quick Sort）实现与逻辑详解

## 代码

```cpp
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
```

---

## 逻辑分析

### **功能**
快速排序是一种基于分治思想的高效排序算法。它通过选择一个基准（pivot），将数组分为两部分，然后递归地排序这两部分。

---

## 步骤与逻辑

### **1. 分区函数 (`partition`)**

```cpp
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
```

#### **逻辑**
- 选择一个基准元素（本实现选择最后一个元素）。
- 遍历数组，将小于或等于基准的元素移到基准的左边。
- 将基准元素移动到正确的位置，返回其索引。

#### **示例**
输入数组：`{10, 7, 8, 9, 1, 5}`  
基准元素：`5`

分区过程：
```
原始数组: {10, 7, 8, 9, 1, 5}
比较并交换: {1, 7, 8, 9, 10, 5}
将基准归位: {1, 5, 8, 9, 10, 7}
返回 pivot 位置: 1
```

---

### **2. 快速排序主函数 (`quickSort`)**

```cpp
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取分区点
        quickSort(arr, low, pi - 1);        // 排序左子数组
        quickSort(arr, pi + 1, high);       // 排序右子数组
    }
}
```

#### **逻辑**
- 递归地对左右子数组进行排序。
- 当子数组的大小为 1 或 0 时，递归终止（自然有序）。

---

## 示例运行过程

初始数组：
```
{10, 7, 8, 9, 1, 5}
```

### **第一轮分区**
基准：`5`
```
{1, 5, 8, 9, 10, 7}
```
- 左子数组：`{1}`
- 右子数组：`{8, 9, 10, 7}`

---

### **第二轮分区（右子数组）**
基准：`7`
```
{1, 5, 7, 9, 10, 8}
```
- 左子数组：`{8}`
- 右子数组：`{9, 10}`

---

### **第三轮分区（右子数组）**
基准：`10`
```
{1, 5, 7, 8, 9, 10}
```

最终排序结果：
```
{1, 5, 7, 8, 9, 10}
```

---

## 复杂度分析

### 时间复杂度
1. **最坏情况**: \( O(n^2) \)
   - 每次选择的基准是最小或最大值，导致分区极不平衡。
2. **平均情况**: \( O(n \log n) \)
   - 数组被大致平分。
3. **最优情况**: \( O(n \log n) \)
   - 每次分区的左右子数组大小接近相等。

### 空间复杂度
- **额外空间**: \( O(\log n) \)
  - 递归栈的深度。

---

## 适用场景

1. **一般数组排序**:
   - 快速排序适用于绝大多数数组排序任务。
2. **高效排序需求**:
   - 快速排序在时间复杂度上的性能优于简单排序算法（如插入排序）。

---

## 优点与缺点

### 优点
- 平均时间复杂度为 \( O(n \log n) \)，性能优越。
- 原地排序，无需额外存储空间。
- 应用广泛，易于实现。

### 缺点
- 最坏情况下时间复杂度为 \( O(n^2) \)。
- 不稳定排序，无法保证相等元素的相对位置不变。

---

## 总结

快速排序是一种基于分治思想的高效排序算法，通常被认为是实际应用中最快的排序方法之一。尽管在最坏情况下时间复杂度为 \( O(n^2) \)，但通过优化（如随机选择基准）可以避免这一问题，是实际应用中的首选排序算法之一。