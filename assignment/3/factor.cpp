#include <iostream>
using namespace std;
int factors(int num, int k)
{
    int cnt = 0;
    while (num % k == 0 && num / k != 0)
    {
        cnt++;
        num /= k;
    }
    return cnt;
}

int main()
{
    int num, k;
    cin >> num >> k;
    cout << factors(num, k);
    return 0;
}