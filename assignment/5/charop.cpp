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
int main()
{
    char s[10] = "abc";
    char ct[10] = "efg";
    cout << strcat(s, ct) << endl;
    cout << strlen(s) << endl;
    cout << (strchr(s,'f') - s);
}