# C++ 输出流 `cout` 用法详解

`cout` 是 C++ 的标准输出流对象，用于将数据输出到控制台。它通常与流插入运算符（`<<`）一起使用。

---

## 基本语法

```cpp
std::cout << data;
```

- **`std::cout`**: 标准输出流对象。
- **`<<`**: 流插入运算符，用于将右侧的数据发送到输出流。
- **`data`**: 要输出的内容，可以是变量、常量、表达式等。

---

## 基本用法

### 单个变量输出

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 42;
    cout << "The number is: " << number << endl;
    return 0;
}
```

**运行示例**:
```
The number is: 42
```

---

### 多个变量输出

可以用多个 `<<` 操作符连续输出多个值。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    cout << "a: " << a << ", b: " << b << endl;
    return 0;
}
```

**运行示例**:
```
a: 10, b: 20
```

---

### 输出表达式结果

可以直接输出表达式的计算结果。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3;
    cout << "Sum: " << (a + b) << ", Product: " << (a * b) << endl;
    return 0;
}
```

**运行示例**:
```
Sum: 8, Product: 15
```

---

### 控制输出格式

#### 输出换行
- 使用 `std::endl` 插入换行符并刷新输出缓冲区。
- 也可以直接使用 `\n` 插入换行符，但不会自动刷新缓冲区。

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Line 1" << endl; // 换行并刷新缓冲区
    cout << "Line 2\n";       // 仅换行
    return 0;
}
```

**运行示例**:
```
Line 1
Line 2
```

#### 输出固定宽度和填充符
使用 `<iomanip>` 库控制输出格式，例如 `setw` 和 `setfill`。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << 42 << endl;          // 输出宽度为10，右对齐
    cout << setfill('-') << setw(10) << 42; // 输出宽度为10，用'-'填充
    return 0;
}
```

**运行示例**:
```
        42
--------42
```

---

### 浮点数输出控制

可以控制浮点数的精度和格式。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.141592653589793;
    cout << "Default: " << pi << endl;
    cout << "Fixed: " << fixed << setprecision(3) << pi << endl; // 固定三位小数
    cout << "Scientific: " << scientific << pi << endl;          // 科学计数法
    return 0;
}
```

**运行示例**:
```
Default: 3.14159
Fixed: 3.142
Scientific: 3.141593e+00
```

---

### 布尔值的输出

默认情况下，布尔值输出为 `0`（false）或 `1`（true）。可以使用 `boolalpha` 将其转换为 `false` 和 `true`。

```cpp
#include <iostream>
using namespace std;

int main() {
    bool value = true;
    cout << "Default: " << value << endl;
    cout << "With boolalpha: " << boolalpha << value << endl;
    return 0;
}
```

**运行示例**:
```
Default: 1
With boolalpha: true
```

---

### 输出字符和字符串

`cout` 可以直接输出字符或字符串。

```cpp
#include <iostream>
using namespace std;

int main() {
    char c = 'A';
    string str = "Hello, World!";
    cout << "Character: " << c << endl;
    cout << "String: " << str << endl;
    return 0;
}
```

**运行示例**:
```
Character: A
String: Hello, World!
```

---

## 多行输出

`cout` 可以在循环中输出多行内容。

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << "Line " << i << endl;
    }
    return 0;
}
```

**运行示例**:
```
Line 1
Line 2
Line 3
Line 4
Line 5
```

---

## 常见问题

### 1. 如何在输出中包含特殊字符？
使用转义字符（如 `\n`, `\t`, `\\` 等）来输出特殊字符。

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello\tWorld!\nThis is a backslash: \\" << endl;
    return 0;
}
```

**运行示例**:
```
Hello   World!
This is a backslash: \
```

---

### 2. 如何输出中文字符？

确保代码文件的编码为 UTF-8，并正确设置终端或 IDE 的字符集。

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "你好，世界！" << endl; // 输出中文
    return 0;
}
```

如果输出乱码，可以考虑以下两种解决方案：
1. 设置编译器或终端的字符集为 UTF-8。
2. 在 Windows 系统中，使用 `std::wcout` 和宽字符：

```cpp
#include <iostream>
#include <locale>
using namespace std;

int main() {
    wcout.imbue(locale("chs")); // 设置本地化
    wcout << L"你好，世界！" << endl;
    return 0;
}
```

---

## 总结

| 功能                | 用法示例                          | 备注                                  |
| ------------------- | --------------------------------- | ------------------------------------- |
| 单变量输出          | `cout << a;`                     | 输出变量值                            |
| 多变量输出          | `cout << a << b;`                | 用 `<<` 连接多个值                    |
| 换行符              | `cout << "Hello\n";`             | 使用 `\n` 或 `endl` 换行              |
| 控制格式            | `setw(10)`                       | 使用 `<iomanip>` 库设置格式            |
| 浮点数精度          | `setprecision(3)`                | 控制浮点数的小数位                    |
| 布尔值              | `cout << boolalpha << true;`     | 显示布尔值为 `true/false`             |
| 输出整行文本        | `cout << "Hello, World!" << endl;`| 用 `endl` 结束当前输出并刷新缓冲区    |

`cout` 是 C++ 中最常用的输出工具之一，搭配各种格式控制功能，可以满足多种输出需求。