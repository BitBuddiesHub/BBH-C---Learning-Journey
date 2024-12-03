# C++ `sizeof` 运算符详解

## 概述

`sizeof` 是一个在 C++ 中非常常用的关键字，用于获取变量或类型的大小（以字节为单位）。它是一个编译时运算符，意味着在编译时就会确定结果。

---

## 语法

```cpp
sizeof(expression);
sizeof(type);
```

- **`expression`**: 一个变量或表达式。
- **`type`**: 数据类型（如 `int`、`double` 或自定义类型）。

---

## 返回值

- `sizeof` 返回一个 `std::size_t` 类型的值，表示内存中该类型或变量所占的字节数。
- 它的值与操作系统、编译器和目标平台的架构（32 位或 64 位）相关。

---

## 使用示例

### 基本类型大小

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    return 0;
}
```

**输出示例**（具体值可能因平台而异）：
```
Size of int: 4 bytes
Size of double: 8 bytes
Size of char: 1 bytes
Size of bool: 1 bytes
```

---

### 数组大小

`sizeof` 可以用来获取数组的总大小（字节数），并结合元素大小计算数组的元素个数：

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Size of array: " << sizeof(arr) << " bytes" << endl;
    cout << "Size of one element: " << sizeof(arr[0]) << " bytes" << endl;
    cout << "Number of elements: " << sizeof(arr) / sizeof(arr[0]) << endl;
    return 0;
}
```

**输出**：
```
Size of array: 20 bytes
Size of one element: 4 bytes
Number of elements: 5
```

---

### 指针与类型

`sizeof` 返回的是指针本身的大小，而不是指针指向的数据的大小：

```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr;
    cout << "Size of pointer: " << sizeof(ptr) << " bytes" << endl;
    return 0;
}
```

**说明**：
- 在 32 位系统中，指针大小通常为 4 字节。
- 在 64 位系统中，指针大小通常为 8 字节。

---

### 自定义结构体

`sizeof` 也可以用于自定义数据类型，比如结构体或类：

```cpp
#include <iostream>
using namespace std;

struct MyStruct {
    char c;
    int i;
    double d;
};

int main() {
    cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << endl;
    return 0;
}
```

**注意**：
- 结构体的大小可能大于其成员变量大小的总和，因为编译器会为对齐（alignment）添加填充字节。

---

### 动态分配与 sizeof

对于动态分配的数组，`sizeof` 只能返回指针的大小，而不是分配的内存大小：

```cpp
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[10];
    cout << "Size of pointer: " << sizeof(arr) << " bytes" << endl;
    delete[] arr;
    return 0;
}
```

**提示**：动态分配的内存大小需要记录或者通过其他方式计算。

---

## 常见问题

1. **`sizeof(char)` 总是返回 1 字节吗？**
   是的，`sizeof(char)` 在任何平台上都等于 1，标准规定每个 `char` 都占 1 字节。

2. **`sizeof` 与 `strlen` 的区别？**
   - `sizeof` 是编译时运算符，用于获取变量或类型的字节数。
   - `strlen` 是一个函数，用于计算字符串的长度（不包括空字符 `\0`）。

   示例：
   ```cpp
   char str[] = "Hello";
   cout << "sizeof(str): " << sizeof(str) << endl; // 包括 '\0'，输出 6
   cout << "strlen(str): " << strlen(str) << endl; // 不包括 '\0'，输出 5
   ```

3. **能否使用 `sizeof` 获取动态数组的大小？**
   不行，`sizeof` 返回的是指针的大小，无法用于动态数组的长度计算。

---