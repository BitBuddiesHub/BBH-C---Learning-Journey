#include <bits/stdc++.h>
using namespace std;
double newton_sqrt(double S, double tolerance = 1e-5, int max_iteration = 10000)
{
    if (S < 0)
    {
        return -1;
    }

    double x = S;
    for (int i = 0; i <= max_iteration; ++i)
    {
        double next_x = 0.5 * (x + S / x);
        if (abs(next_x - x) < tolerance)
        {
            return next_x;
        }
        x = next_x;
    }

    return x;
}
int main()
{
    double x;
    double res = 0;
    do
    {
        cout << "input the num to sqrt:";
        cin >> x;
        res = newton_sqrt(x);
        if (res != -1)
        {
            cout << "result is:" << res << endl;
            break;
        }
    } while (res = -1);
    return 0;
}
