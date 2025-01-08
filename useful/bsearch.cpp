#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int BSearch(int a[], int num, int n)
{
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (num < a[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else if (num > a[mid])
        {
            left = mid;
            mid = (left + right) / 2;
        }
        else
            return mid + 1;
    }
    return -1;
}

int main()
{
    int a[10] = {1, 3, 6, 24, 35, 45, 63, 75, 80, 90};
    cout << BSearch(a, 24, 10);
}