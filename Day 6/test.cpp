#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 9, y = 3;
    while (x / y)
    {
        switch (x % y)
        {
        case 0:
            x -= y - 1;
        case 1:
            x %= y++;
        case 2:
            y += x++;
        }
    }
    cout << x <<" "<< y;
}