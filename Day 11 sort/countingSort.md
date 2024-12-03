# 计数排序（Counting Sort）实现与逻辑详解

## 代码

```cpp
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
```

---

## 逻辑分析

### **功能**
计数排序是一种非比较排序算法，利用计数数组存储每个元素出现的次数，通过计算每个元素在排序数组中的位置来完成排序。

---

## 步骤与逻辑

### **1. 找到最大值和最小值**
```cpp
int maxElement = *max_element(arr.begin(), arr.end());
int minElement = *min_element(arr.begin(), arr.end());
int range = maxElement - minElement + 1;
```
- **作用**: 找出数组的最大值和最小值，计算元素值的范围。
- **逻辑**: `range` 是计数数组的大小，用于覆盖所有可能的整数值。

#### 示例
输入数组：`{4, 2, 2, 8, 3, 3, 1}`  
计算结果：
```
maxElement = 8
minElement = 1
range = 8 - 1 + 1 = 8
```

---

### **2. 初始化计数数组**
```cpp
vector<int> count(range, 0);
```
- **作用**: 创建并初始化计数数组，每个元素初始值为 `0`。
- **逻辑**: 计数数组的索引范围为 `[0, range-1]`，用于统计每个元素的频率。

---

### **3. 统计每个元素出现的次数**
```cpp
for (int num : arr)
    count[num - minElement]++;
```
- **作用**: 遍历输入数组，将每个元素出现的次数存储到计数数组对应的索引中。
- **逻辑**: 索引偏移量为 `num - minElement`，确保最小值映射到 `count[0]`。

#### 示例
输入数组：`{4, 2, 2, 8, 3, 3, 1}`  
统计后：
```
count = {1, 2, 2, 1, 0, 0, 1, 0}
解释：
  1 出现 1 次 -> count[0] = 1
  2 出现 2 次 -> count[1] = 2
  3 出现 2 次 -> count[2] = 2
  4 出现 1 次 -> count[3] = 1
  ...
  8 出现 1 次 -> count[7] = 1
```

---

### **4. 累加计数**
```cpp
for (int i = 1; i < range; i++)
    count[i] += count[i - 1];
```
- **作用**: 累加计数数组，表示每个元素在输出数组中的最后位置。
- **逻辑**: 对于某个索引 `i`，`count[i]` 表示小于等于该元素的元素个数。

#### 示例
累加后：
```
count = {1, 3, 5, 6, 6, 6, 7, 7}
解释：
  小于等于 1 的有 1 个
  小于等于 2 的有 3 个
  小于等于 3 的有 5 个
  ...
```

---

### **5. 构造输出数组**
```cpp
for (int i = arr.size() - 1; i >= 0; i--) {
    output[count[arr[i] - minElement] - 1] = arr[i];
    count[arr[i] - minElement]--;
}
```
- **作用**: 倒序遍历输入数组，将每个元素放入输出数组对应的位置。
- **逻辑**: 使用计数数组确定元素的正确位置，同时递减计数以处理重复元素。

#### 示例
输入数组：`{4, 2, 2, 8, 3, 3, 1}`  
构造过程：
```
1. 处理 1 -> output[0] = 1 -> count[0]--
2. 处理 3 -> output[4] = 3 -> count[2]--
3. 处理 3 -> output[3] = 3 -> count[2]--
4. 处理 8 -> output[6] = 8 -> count[7]--
...
最终 output = {1, 2, 2, 3, 3, 4, 8}
```

---

### **6. 复制回原数组**
```cpp
arr = output;
```
- **作用**: 将排序结果复制回原数组。

---

## 示例运行过程

输入数组：
```
{4, 2, 2, 8, 3, 3, 1}
```

1. **统计次数**：
```
count = {1, 2, 2, 1, 0, 0, 1, 0}
```

2. **累加计数**：
```
count = {1, 3, 5, 6, 6, 6, 7, 7}
```

3. **构造输出数组**：
```
output = {1, 2, 2, 3, 3, 4, 8}
```

4. **复制回原数组**：
```
arr = {1, 2, 2, 3, 3, 4, 8}
```

---

## 复杂度分析

### 时间复杂度
- **统计次数**: \( O(n) \)
- **累加计数**: \( O(k) \)
- **构造输出数组**: \( O(n) \)
- **总复杂度**: \( O(n + k) \)，其中 \( k \) 是元素值的范围。

### 空间复杂度
- 计数数组和输出数组：\( O(n + k) \)。

---

## 适用场景

1. **整数排序**:
   - 适合整数或范围较小的正数排序。
2. **输入范围明确**:
   - 对于范围较大的数据，计数数组可能消耗过多内存。

---

## 优点与缺点

### 优点
- 时间复杂度接近线性。
- 非比较排序，效率高。

### 缺点
- 需要额外的空间存储计数数组。
- 不适合范围较大的数据。

---

## 总结

计数排序是一种高效的非比较排序算法，特别适合小范围整数的排序任务。在实际应用中，可根据输入数据范围和内存限制来判断其适用性。