// C++程序将十进制数转换为二进制数
#include <iostream>
using namespace std;
  
// 将十进制转换为二进制的函数
void decToBinary(int n)
{
    // 数组存储二进制数
    int binaryNum[32];
  
    // 二进制数组的计数器
    int i = 0;
    while (n > 0) 
    {
        // 将余数存储在二进制数组中
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
  
    // 倒序打印二进制数组
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
  
// 主程序
int main()
{
    int n = 17;
    decToBinary(n);
    return 0;
}  
