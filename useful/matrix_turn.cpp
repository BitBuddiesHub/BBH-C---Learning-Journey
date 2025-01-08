#include <iostream>
using namespace std;
void output_turn_right(int a[], int b[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i * cols + j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            b[j * rows + (rows -1 - i) ] = a[i * cols + j];
        }
    }
/*
00 01 02 03   00 -> 02 01 -> 12 02 -> 22 03 -> 32
10 11 12 13   10 -> 01 11 -> 11 12 -> 21 13 -> 31
20 21 22 23

00 01 02
10 11 12
20 21 22
30 31 32
*/
    cout<<endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << b[i * rows + j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int a[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int b[12] = {0};
    output_turn_right(a, b, 3, 4);
}
