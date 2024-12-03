# `strcmp` 函数详解

## 1. 函数概述

`strcmp` 是 C 标准库中 `<string.h>` 提供的一个函数，用于逐字符比较两个字符串的内容，结果用于判断字符串的相对大小或相等关系。

### 函数声明
```c
int strcmp(const char *str1, const char *str2);
```

### 参数说明
- **`str1`**: 指向第一个字符串的指针。
- **`str2`**: 指向第二个字符串的指针。

### 返回值
- 返回值为整数，具体含义如下：
  - **小于 0**: 如果 `str1` 小于 `str2`。
  - **等于 0**: 如果 `str1` 等于 `str2`。
  - **大于 0**: 如果 `str1` 大于 `str2`。

---

## 2. 使用方法

### 基本用法
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "banana";

    int result = strcmp(str1, str2);

    if (result < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str2);
    } else if (result == 0) {
        printf("\"%s\" is equal to \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" is greater than \"%s\"\n", str1, str2);
    }

    return 0;
}
```

### 运行结果
```
"apple" is less than "banana"
```

---

## 3. 工作原理

`strcmp` 按照字典顺序（ASCII 值）逐字符比较字符串：
1. 从字符串的第一个字符开始，比较 `str1` 和 `str2` 对应位置的字符。
2. 如果找到第一个不同的字符，则返回它们的 ASCII 值差（`str1[i] - str2[i]`）。
3. 如果两个字符串完全相等，则返回 `0`。

---

## 4. 示例代码

### 4.1 字符串相等
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello";
    char str2[] = "hello";

    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}
```

**运行结果：**
```
Strings are equal.
```

### 4.2 字符串排序
`strcmp` 可以用来对字符串数组进行排序。
```c
#include <stdio.h>
#include <string.h>

void sortStrings(char arr[][20], int n) {
    char temp[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) { // 按字典顺序排序
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    char strings[5][20] = {"apple", "orange", "banana", "grape", "kiwi"};
    int n = 5;

    sortStrings(strings, n);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
```

**运行结果：**
```
Sorted strings:
apple
banana
grape
kiwi
orange
```

---

## 5. 注意事项

### 5.1 区分大小写
- `strcmp` 是大小写敏感的。
```c
strcmp("Apple", "apple"); // 返回负值，因为 'A' < 'a'
```

### 5.2 空字符串
- 如果任意一个字符串为空，`strcmp` 将直接比较另一个字符串的第一个字符与 `\0`。
```c
strcmp("", "hello"); // 返回负值
strcmp("hello", ""); // 返回正值
```

### 5.3 不检查 NULL 指针
- 如果 `str1` 或 `str2` 是 NULL，则会导致未定义行为。
```c
char *str = NULL;
strcmp(str, "hello"); // 未定义行为
```

**解决方法：**
在调用 `strcmp` 前检查字符串是否为 NULL。
```c
if (str1 == NULL || str2 == NULL) {
    fprintf(stderr, "Error: NULL string input.\n");
    return -1;
}
```

---

## 6. 实现原理

以下是 `strcmp` 的一个简单实现：
```c
int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
```

**实现逻辑：**
1. 遍历两个字符串，同时比较各字符是否相等。
2. 如果遇到不同字符，返回它们的 ASCII 差值。
3. 如果遍历到终止符 `\0`，说明两个字符串相等，返回 0。

---

## 7. 应用场景

### 7.1 字符串比较
- 判断两个字符串是否相等，或比较大小。

### 7.2 字符串排序
- 按字典顺序对字符串数组进行排序。

### 7.3 查找匹配字符串
- 用于字符串列表中查找特定字符串。

---

## 8. `strcmp` 与其他比较函数的对比

| 功能                | `strcmp`                        | `strncmp`                       |
|---------------------|----------------------------------|----------------------------------|
| 比较方式            | 比较整个字符串                  | 比较前 `n` 个字符               |
| 区分大小写          | 区分                           | 区分                            |
| 返回值含义          | 相对大小或相等                  | 相对大小或相等                  |

---

## 9. 总结

`strcmp` 是 C 语言中重要的字符串比较函数，用于判断字符串的相对大小或相等性。使用时需注意以下几点：
1. 确保传递的字符串非 NULL。
2. 理解返回值的含义，特别是对于大小写敏感的比较。
3. 在需要限制比较字符数时，可以使用 `strncmp`。

合理使用 `strcmp`，可以有效完成字符串比较相关的任务。

# 附录 10: Unicode 和非 ASCII 字符串的比较

在 C 标准库的 `strcmp` 函数中，字符串的比较基于 ASCII 编码，但当处理其他语言（如汉字）或 Unicode 字符串时，比较方式可能需要调整，具体取决于编码方式和语言的排序规则。

---

## 1. 汉字比较的特殊性

### 汉字的编码
- 汉字通常使用以下编码方式之一：
  - **GB2312/GBK/GB18030**（简体中文，常用于中国大陆）
  - **Big5**（繁体中文，常用于台湾和香港）
  - **UTF-8**（通用 Unicode 编码）
  - **UTF-16**（广泛使用于现代系统）

### 在 C 中比较汉字字符串
- 如果字符串采用 GBK 或 Big5 编码，`strcmp` 仍然可以比较，因为这些编码是基于字节的，`strcmp` 会逐字节比较两个字符串。
- 然而，这种比较仅基于字节序，**不符合语言学上的字典顺序**。

**示例：**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "苹果"; // GBK 编码
    char str2[] = "香蕉"; // GBK 编码

    int result = strcmp(str1, str2);

    if (result < 0) {
        printf("\"%s\" 小于 \"%s\"\n", str1, str2);
    } else if (result == 0) {
        printf("\"%s\" 等于 \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" 大于 \"%s\"\n", str1, str2);
    }

    return 0;
}
```

- **问题**: 使用 `strcmp` 直接比较汉字字符串可能导致结果与预期不符，因为字节序不等于语言学上的顺序。

---

## 2. Unicode 字符串的比较

### Unicode 的编码方式
- **UTF-8**：每个字符编码为 1 到 4 个字节，向后兼容 ASCII。
- **UTF-16**：每个字符编码为 2 或 4 个字节。
- **UTF-32**：每个字符固定为 4 个字节。

`strcmp` 无法正确处理 UTF-8 或 UTF-16 编码的多字节字符，因为它逐字节比较，可能导致错误结果。

### 示例：UTF-8 字符比较
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "你好"; // UTF-8 编码
    char str2[] = "世界"; // UTF-8 编码

    int result = strcmp(str1, str2);

    if (result < 0) {
        printf("\"%s\" 小于 \"%s\"\n", str1, str2);
    } else if (result == 0) {
        printf("\"%s\" 等于 \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" 大于 \"%s\"\n", str1, str2);
    }

    return 0;
}
```

- **问题**: 结果仅基于字节序，可能与预期的语言学排序不一致。

---

## 3. 语言学排序规则

### Locale 支持
在 C 标准库中，可以使用 `setlocale` 函数设置区域，并通过 `strcoll` 函数进行语言学排序比较。

**示例：使用语言环境进行汉字比较**
```c
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_COLLATE, "zh_CN.UTF-8");

    char str1[] = "苹果";
    char str2[] = "香蕉";

    int result = strcoll(str1, str2);

    if (result < 0) {
        printf("\"%s\" 小于 \"%s\"\n", str1, str2);
    } else if (result == 0) {
        printf("\"%s\" 等于 \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" 大于 \"%s\"\n", str1, str2);
    }

    return 0;
}
```

- **`strcoll` 的作用**: 根据语言环境规则（Locale）进行字符串比较。
- **优势**: 正确处理 Unicode 字符，并根据语言习惯进行排序。

---

## 4. 不同语言的库支持

### C++ 中的比较
在 C++ 中，可以使用标准库的 `std::wstring` 或 `std::u32string`，配合自定义的排序规则进行比较。

**示例：使用 `std::locale`**
```cpp
#include <iostream>
#include <locale>

int main() {
    std::locale loc("zh_CN.UTF-8");
    std::wstring str1 = L"苹果";
    std::wstring str2 = L"香蕉";

    if (std::use_facet<std::collate<wchar_t>>(loc).compare(str1.c_str(), str1.c_str() + str1.size(),
                                                           str2.c_str(), str2.c_str() + str2.size()) < 0) {
        std::wcout << L"苹果 小于 香蕉" << std::endl;
    } else {
        std::wcout << L"苹果 大于等于 香蕉" << std::endl;
    }

    return 0;
}
```

### Python 中的比较
在 Python 中，字符串比较是内置支持 Unicode 的，直接基于字符的代码点值（Unicode 值）进行比较。

**示例：**
```python
str1 = "苹果"
str2 = "香蕉"

if str1 < str2:
    print(f'"{str1}" 小于 "{str2}"')
else:
    print(f'"{str1}" 大于等于 "{str2}"')
```

---

## 5. 关键点总结

- **ASCII 字符比较**:
  - 基于字节序，`strcmp` 可直接处理。

- **Unicode 或汉字比较**:
  - 直接使用 `strcmp` 比较结果可能不符合语言学规则。
  - 使用 `strcoll` 或依赖其他库（如 ICU、Boost）进行语言学排序。

- **跨语言支持**:
  - Python 等现代语言内置 Unicode 支持，比较结果符合 Unicode 标准。
  - 在 C/C++ 中，处理 Unicode 字符需要额外设置或使用外部库（如 ICU）。

---

## 6. 推荐方法

1. **如果需要语言学排序**:
   - 在 C 中使用 `strcoll` 配合适当的 `setlocale` 设置。
   - 在 C++ 中使用 `std::locale` 或 ICU 库。

2. **如果处理 Unicode 字符串**:
   - 确保输入字符串的编码一致（推荐 UTF-8 或 UTF-16）。
   - 对于跨平台应用，建议使用 ICU 库。

3. **避免的问题**:
   - 不同编码混用导致结果不可预测。
   - 忽略语言特定的排序规则，仅使用字节序比较。