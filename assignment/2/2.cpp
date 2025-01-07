#include <iostream>
using namespace std;

int func(int x)
{
    x /= 10;
    switch (x)
    {
    case 9:
        return 5;
    case 8:
        return 4;
    case 7:
        return 3;
    case 6:
        return 2;
    default:
        return 1;
    }
}

int main()
{
    int x;
    cin >> x;
    cout << func(x);
}