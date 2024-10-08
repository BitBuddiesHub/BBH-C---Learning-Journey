#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "输入三个不大于100的正整数：";
    cin >> a >> b >> c;
    int sum = a + b + c;
    int product = a * b * c;
    double average = sum / 3.0;
    cout << "和：" << sum << " 积：" << product << " 平均值：" << average << endl;
    return 0;
}
