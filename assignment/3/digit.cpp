#include <iostream>
#include <cmath>
using namespace std;

int digit(int x, int y)
{
    for (int i = 1; i < y && x != 0; i++)
    {
        x /= 10;
        // cout << x << endl;
    }
    return x % 10;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << digit(x, y) << endl;
}