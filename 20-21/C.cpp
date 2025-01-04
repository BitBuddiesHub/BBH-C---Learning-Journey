#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

void create(const char *filename, int num, int min, int max);
int solve(const char *str, int &num1, int &num2);

int main()
{
    char filename[10] = "test.txt";

    int num, min, max;

    cout << "请输入算式的最小值：";
    cin >> min;
    cout << "\n"
         << "请输入算式的最大值：";
    cin >> max;
    cout << "\n"
         << "请输入算式的个数：";
    cin >> num;

    create(filename, num, min, max);

    cout << "所有算式已经生成" << endl;

    ifstream inFile;
    inFile.open(filename);

    int i;
    int count = 0;
    for (i = 1; i <= num; ++i)
    {
        char str[20];
        int num1, num2;
        int result, answer;

        if (inFile.getline(str, 20))
        {
            result = solve(str, num1, num2);
        }

        cout << str << '=';

        cin >> answer;

        if (answer == result)
        {
            cout << "答题正确";
            count++;
        }
        else
        {
            cout << "答题错误，正确答案是：" << num1 << "+" << num2 << "=" << result;
        }
    }

    cout << "本次测验共" << num << "题，你答对了" << count << "题";
    setprecision(2);
    cout << "答题正确率为" << count / num * 100 << "%";

    return 0;
}

void create(const char *filename, int num, int min, int max)
{
    srand(time(0));
    ofstream outFile;
    outFile.open(filename);
    for (int i = 0; i <= num; i++)
    {
        outFile << (rand() % (max - min) + min) << "+" << (rand() % (max - min) + min) << endl;
    }
}

int solve(const char *str, int &num1, int &num2)
{
    const char *ptr = &(*str);

    num1 = atoi(ptr);

    while (*ptr != '\0' && *ptr <= '9' && *ptr >= '0')
    {
        ptr++;
    }
    ptr++;

    num2 = atoi(ptr);

    return num1 + num2;
}
