#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    // 模拟掷一个六面骰子
    int diceRoll = 1 + rand() % 6; // 生成 1 到 6 的随机数
    cout << "掷骰子结果: " << diceRoll << endl;

    // 模拟掷两个骰子的和
    int diceRoll1 = 1 + rand() % 6;
    int diceRoll2 = 1 + rand() % 6;
    cout << "两个骰子的点数: " << diceRoll1 << " 和 " << diceRoll2 << endl;
    cout << "总和: " << diceRoll1 + diceRoll2 << endl;

    return 0;
}
