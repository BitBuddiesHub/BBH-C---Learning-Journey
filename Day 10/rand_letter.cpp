#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // 生成一个随机小写字母
    char randomLowercase = 'a' + rand() % 26; // 'a' ASCII值是97
    cout << "随机小写字母: " << randomLowercase << endl;

    // 生成一个随机大写字母
    char randomUppercase = 'A' + rand() % 26; // 'A' ASCII值是65
    cout << "随机大写字母: " << randomUppercase << endl;

    // 生成一个随机数字字符
    char randomDigit = '0' + rand() % 10; // '0' ASCII值是48
    cout << "随机数字字符: " << randomDigit << endl;

    return 0;
}
