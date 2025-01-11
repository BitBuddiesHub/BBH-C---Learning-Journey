#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a[20] = "Hello CPP!";
    char *b = a;
    cout << sizeof(*b) << endl;
    cout << sizeof(b) << endl;
    cout << strlen(b) << endl;
    // cout << strlen(*b);
    cout << b << endl;
    cout << *b << endl;
}