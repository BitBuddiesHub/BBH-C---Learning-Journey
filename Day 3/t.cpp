#include <iostream>
using namespace std;
int main()
{
    long int a;
    cout << "input a num:";
    cin >> a;

    while (a / 10 != 0)
    {
        cout << a % 10;
        a /= 10;
    }
    cout << a % 10 << endl;
}