#include <iostream>
#include <cmath>
using namespace std;

double bin_to_dec(long long int bin)
{
    double tmp = 0;
    int cnt = 0;
    while (bin != 0)
    {
        tmp += pow(2, cnt) * (bin % 2);
        bin /= 10;
        cnt++;
    }
    return tmp;
}

double dec_to_bin(long long int bin)
{
    double tmp = 0;
    int cnt = 0;
    while (bin != 0)
    {
        tmp += pow(2, cnt) * (bin % 2);
        bin /= 10;
        cnt++;
    }
    return tmp;
}

int main()
{
    long long int bin = 0;
    cin >> bin;
    cout << bin_to_dec(bin);
}