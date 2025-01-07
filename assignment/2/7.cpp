#include <iostream>
using namespace std;
long long int func(int x)
{
    if (x == 1)
    {
        return x * 1;
    }
    else
        return x * func(x - 1);
}

int main()
{
    long long int x = 0, cnt = 0;
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        cnt += func(i);
    }
    cout << cnt;
}