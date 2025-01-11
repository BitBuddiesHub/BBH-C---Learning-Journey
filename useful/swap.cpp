#include <iostream>
using namespace std;
void swap(int &c, int &d)
{
    int tmp = 0;
    tmp = d;
    d = c;
    c = tmp;
}

int main()
{
    int a = 1;
    int b = 2;
    int &c = b;
    c = 3;
    // swap(a, b);
    cout << a << b;
}