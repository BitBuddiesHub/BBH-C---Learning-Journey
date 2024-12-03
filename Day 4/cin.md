# C++ 输入流 `cin` 用法详解

`cin` 是 C++ 的标准输入流对象，用于从键盘读取用户输入，通常搭配 `cout` 一起使用。它位于 `iostream` 头文件中，操作符为 `>>`（流提取运算符）。

---

## 基本语法

```cpp
std::cin >> variable;
```

- **`std::cin`**: 标准输入流对象。
- **`>>`**: 流提取运算符，用于将输入的数据存储到右侧变量中。
- **`variable`**: 要存储输入数据的变量。

---

## 基本用法

### 单个变量输入

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number; // 从用户输入读取一个整数
    cout << "You entered: " << number << endl;
    return 0;
}
```

**运行示例**:
```
Enter a number: 42
You entered: 42
```

---

### 多个变量输入

可以用多个 `>>` 操作符连续读取多个输入。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b; // 输入两个整数
    cout << "You entered: " << a << " and " << b << endl;
    return 0;
}
```

**运行示例**:
```
Enter two numbers: 10 20
You entered: 10 and 20
```

---

## 处理不同数据类型

`cin` 可以处理多种数据类型，但输入的类型必须与变量类型匹配。

```cpp
#include <iostream>
using namespace std;

int main() {
    int integer;
    double floating;
    char character;

    cout << "Enter an integer, a double, and a character: ";
    cin >> integer >> floating >> character;

    cout << "You entered: " << integer << ", " << floating << ", and '" << character << "'" << endl;
    return 0;
}
```

**运行示例**:
```
Enter an integer, a double, and a character: 42 3.14 x
You entered: 42, 3.14, and 'x'
```

---

## 处理字符串输入

### 读取单个单词

`cin` 默认会以空格或换行符分隔输入，因此仅读取单个单词。

```cpp
#include <iostream>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "You entered: " << word << endl;
    return 0;
}
```

**运行示例**:
```
Enter a word: HelloWorld
You entered: HelloWorld
```

### 读取整行输入

使用 `getline` 读取整行输入。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Enter a sentence: ";
    getline(cin, line); // 读取整行输入
    cout << "You entered: " << line << endl;
    return 0;
}
```

**运行示例**:
```
Enter a sentence: Hello World!
You entered: Hello World!
```

---

## 常见问题

### 问题 1: 忽略换行符导致输入被跳过

`cin` 在读取输入后，换行符（`'\n'`）可能留在缓冲区中，从而影响后续读取。

#### 示例问题

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    string line;

    cout << "Enter a number: ";
    cin >> number; // 读取整数
    cout << "Enter a sentence: ";
    getline(cin, line); // 可能会跳过输入

    cout << "Number: " << number << ", Sentence: " << line << endl;
    return 0;
}
```

#### 解决方法

在使用 `getline` 前调用 `cin.ignore()` 清除缓冲区。

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

修改后的代码：
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    string line;

    cout << "Enter a number: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区
    cout << "Enter a sentence: ";
    getline(cin, line);

    cout << "Number: " << number << ", Sentence: " << line << endl;
    return 0;
}
```

---

## 输入验证

### 检查输入是否有效

使用 `cin.fail()` 检查是否输入了无效数据。

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (cin.fail()) { // 检查输入是否有效
        cout << "Invalid input!" << endl;
    } else {
        cout << "You entered: " << number << endl;
    }
    return 0;
}
```

**运行示例**:
```
Enter a number: abc
Invalid input!
```

### 清除无效输入

如果输入无效，可以使用以下步骤清除错误状态和缓冲区：

```cpp
cin.clear(); // 清除错误状态
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区
```

---

## 多行输入的读取

在循环中读取输入，直到某个条件结束。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "Enter multiple lines (type 'exit' to quit):" << endl;

    while (true) {
        getline(cin, line);
        if (line == "exit") {
            break; // 结束循环
        }
        cout << "You entered: " << line << endl;
    }

    return 0;
}
```

**运行示例**:
```
Enter multiple lines (type 'exit' to quit):
Hello
You entered: Hello
C++
You entered: C++
exit
```

---

## 小结

| 用法                     | 描述                                         |
| ------------------------ | -------------------------------------------- |
| `cin >> variable`        | 读取单个变量，按空格、换行符分隔              |
| `getline(cin, string)`   | 读取整行输入，包括空格                        |
| `cin.ignore()`           | 清除缓冲区中的多余字符                        |
| `cin.clear()`            | 清除错误状态                                  |
| `cin.fail()`             | 检查输入是否有效                              |

通过合理使用 `cin` 和其他输入处理函数，可以处理多种输入场景并避免常见问题。