#include <iostream>
#include <iomanip>

using namespace std;

char *strcat(char *s, const char *ct)
{
    char *tmp = s;
    while (*++tmp != '\0')
        ;
    while ((*tmp++ = *ct++) != '\0')
        ;

    return s;
}

int strlen(const char *s)
{
    int cnt = 0;
    while (*s++ != '\0')
        cnt++;
    return cnt;
}

char *reverse(char *s)
{
    if (s == nullptr)
        return s; // 处理空指针情况

    char *start = s;
    char *end = s;

    // 找到字符串的末尾
    while (*end != '\0')
    {
        end++;
    }
    end--; // 指向最后一个有效字符，而不是 '\0'

    // 交换字符
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return s; // 返回原字符串指针
}

char *strchr(const char *cs, char c)
{
    char *tmp = (char *)cs;
    while (*tmp++ != '\0')
    {
        if (*tmp != c)
        {
            return tmp;
        }
    }
    return nullptr;
}

#include <iostream>
using namespace std;

char *strstr(const char *cs1, const char *cs2) {
    if (!cs1 || !cs2) return nullptr;  // 如果任一字符串为空，直接返回 nullptr

    char *start_1 = (char *)cs1;       // 遍历 cs1 的起始位置
    const char *sub;                   // 用于匹配 cs2 的子串

    while (*start_1 != '\0') {         // 遍历 cs1
        if (*start_1 == *cs2) {        // 找到可能的匹配起点
            sub = cs2;                 // 初始化子串指针
            char *tmp = start_1;

            while (*tmp == *sub && *sub != '\0') {  // 检查后续字符是否匹配
                tmp++;
                sub++;
            }

            if (*sub == '\0') {        // 如果完整匹配
                return start_1;
            }
        }
        start_1++;                     // 移动到 cs1 的下一个字符
    }

    return nullptr;                    // 未找到匹配
}


int main()
{
    char s[10] = "abc";
    char ct[10] = "efg";
    cout << strcat(s, ct) << endl;
    cout << strlen(s) << endl;
    cout << (strchr(s,'f') - s);
}