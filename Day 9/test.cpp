#include <bits/stdc++.h>
using namespace std;
void fun(int n, int m)
{
    cout << n << '\t' << m << endl;

    if (n < m)
        fun(n + 1, m - 1);
}

int main()
{
    fun(1, 5);
    return 0;
}