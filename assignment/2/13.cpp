#include <iostream>
#include <cmath>
using namespace std;

long double func_2(double epsilon = 1e-5) {
    long double tmp = 0.0;
    long double term;
    int cnt = 0;

    do {
        term = pow(-1, cnt) / (2.0 * cnt + 1);
        tmp += term;
        cnt++;
    } while (fabs(term) > epsilon);

    return 4 * tmp;
}

int main() {
    cout << "Approximation of π: " << func_2() << endl;
    return 0;
}
