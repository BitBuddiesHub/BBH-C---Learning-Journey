```cpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
long hex2int(const string &hexStr)
{
    char *offset;
    if (hexStr.length() > 2)
    {
        if (hexStr[0] == '0' && hexStr[1] == 'x')
        {
            return strtol(hexStr.c_str(), &offset, 0);
        }
    }
    return strtol(hexStr.c_str(), &offset, 16);
}
int main()
{
    string str1 = "0x12AB";
    cout << hex2int(str1) << endl;
    string str2 = "12AB";
    cout << hex2int(str2) << endl;
    string str3 = "QAFG";
    cout << hex2int(str3) << endl;
}
```
這段程式碼的主要概念是 **將十六進制字串轉換為整數值**，並處理有「0x」前綴的十六進制字串與純數字字串的情況。

以下是程式碼的重要部分與說明：

---

### 主要功能
1. 函式 **`hex2int`**:
   - 接收一個字串參數 `hexStr`，代表一個十六進制數字（可能有 "0x" 前綴）。
   - 如果字串以 "0x" 開頭，使用 `strtol` 函式將字串轉為整數，基數為自動判斷（`base=0`）。
   - 如果沒有 "0x" 前綴，則假設基數為 16。
   - 若字串無法正確解析為十六進制數字，會返回 0。

2. 主程式 **`main`**:
   - 測試不同的十六進制字串輸入，分別有：
     - 帶有 "0x" 前綴的十六進制字串。
     - 沒有 "0x" 前綴的十六進制字串。
     - 非法字串（無法轉換為數字）。

3. 使用的函式 **`strtol`**:
   - 標準 C 函式，用於將字串轉換為長整數，支援自動或指定基數（如 10、16）。

---

### 範例說明

以下是程式執行的過程與輸出：

#### 1. 帶有 "0x" 前綴
```cpp
string str1 = "0x12AB";
cout << hex2int(str1) << endl;
```
- 字串 `"0x12AB"` 表示十六進制數字 `12AB`。
- 轉換後的整數值為 `4779`（十進制表示）。
- **輸出：** `4779`

#### 2. 沒有 "0x" 前綴
```cpp
string str2 = "12AB";
cout << hex2int(str2) << endl;
```
- 字串 `"12AB"` 表示十六進制數字 `12AB`。
- 轉換後的整數值同樣為 `4779`。
- **輸出：** `4779`

#### 3. 非法字串
```cpp
string str3 = "QAFG";
cout << hex2int(str3) << endl;
```
- 字串 `"QAFG"` 並不是有效的十六進制數字。
- 轉換失敗時，`strtol` 返回 `0`。
- **輸出：** `0`

---

### 重點概念
- **十六進制轉換：** 程式處理了不同格式的十六進制輸入，並能自動判斷是否有 "0x" 前綴。
- **錯誤處理：** 非法字串輸入時，程式返回安全的值（0）。
- **應用場景：** 這段程式碼適合用於需要處理十六進制數字的場合，如解析設定檔、處理資料格式等。

---

### 延伸應用範例
假設你有以下輸入：
```cpp
string userInput = "0xFF";
cout << hex2int(userInput) << endl;
```
- **輸出：** `255`（十進制）。