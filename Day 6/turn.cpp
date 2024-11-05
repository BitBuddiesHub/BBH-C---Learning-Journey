#include <iostream>
using namespace std;

int main() {
    // 定义一个整数变量
    int x = 0;

    // 示例1：使用goto语句跳转
    cout << "Example 1: goto statement" << endl;
    cout << "Before goto" << endl;
    
    goto jump_point;  // 跳转到 jump_point 标签处执行
    cout << "This line will be skipped due to goto" << endl;

jump_point:
    cout << "After goto, program jumps here" << endl;

    // 示例2：使用break跳出循环
    cout << "\nExample 2: break statement in a loop" << endl;
    while (true) {
        cout << "Enter a number (0 to exit loop): ";
        cin >> x;
        if (x == 0) {
            break;  // 如果输入0，则退出循环
        }
        cout << "You entered: " << x << endl;
    }
    cout << "Exited loop using break" << endl;

    // 示例3：使用continue跳过当前循环的剩余部分
    cout << "\nExample 3: continue statement in a loop" << endl;
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) {
            cout << "Skipping number 3 using continue" << endl;
            continue;  // 跳过本次循环的剩余部分
        }
        cout << "Current number: " << i << endl;
    }

    // 示例4：使用return语句提前返回函数
    cout << "\nExample 4: return statement" << endl;
    cout << "Function will return before reaching this point" << endl;
    return 0;  // 提前退出函数
    // 下面的代码不会执行，因为return已经将控制权返回了
    cout << "This line will never be executed due to return" << endl;

    return 0;
}
