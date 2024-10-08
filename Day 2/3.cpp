#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
    double radius;
    cout << "输入球的半径：";
    cin >> radius;
    double volume = (4.0 / 3.0) * PI * radius * radius * radius;
    cout << "球的体积：" << volume << endl;
    return 0;
}
