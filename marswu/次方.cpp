#include <bits/stdc++.h>

using namespace std;

int qpow(int a, int b) {
    if (b == 0) return 1;
    int tmp = qpow(a, b / 2);
    if (b % 2 == 0) return tmp * tmp;
    else return tmp * tmp * a; 
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b); //a^b
    return 0;
}