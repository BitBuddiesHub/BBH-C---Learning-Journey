#include <iostream>
using namespace std;
int func(int x)
{
    return x >= 10 ? 3 * x - 11 : (1 <= x && x <= 10) ? 2 * x - 1
                                                      : x;
}
int main()
{
    int x;
    cin>>x;
    cout<<func(x);
}