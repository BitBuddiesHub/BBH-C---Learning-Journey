#include <iostream>
using namespace std;
inline bool func(char k)
{
    if (k >= '0' && k <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char k;
    k = cin.get();
    cout << func(k);
}