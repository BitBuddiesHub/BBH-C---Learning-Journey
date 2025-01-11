#include <iostream>
using namespace std;

int main()
{
    int n = -1;
    char s[5] = {'A', 'B', 'C'};
    char *p = s;

    // 输出 n 右移 2 位的结果和 n 的按位取反结果
    cout << (n >> 2) << '\t' << ~n << endl;

    // 指针 p 指向下一个字符
    p++;

    // 输出指针 p 所指向的字符串
    cout << p << endl;

    // 输出指针 p 所指向的字符与 s[0] 的差值
    cout << *p - s[0] << endl;

    // 输出数组 s 的大小和指针 p 的大小
    cout << sizeof(s) << '\t' << sizeof(p) << endl;

    // 将指针 p 所指向的字符设置为 '\0'
    *p = 0;

    // 循环，直到 *p 不在 0 到 199 的范围内
    while (*p < 200 && *p >= 0)
    {
        (*p)++;
        cout << *p << endl;
        n++;
        cout << n << endl;
    }

    return 0;
}
