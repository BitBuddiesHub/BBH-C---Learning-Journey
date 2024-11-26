#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 检查括号匹配的函数
bool isValidParentheses(const string& expression) {
    stack<char> stk; // 定义一个堆栈用于存储括号

    // 遍历表达式中的每个字符
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // 遇到左括号，压入栈中
            stk.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // 遇到右括号，检查栈是否为空
            if (stk.empty()) {
                return false; // 没有匹配的左括号
            }
            // 检查栈顶是否是对应的左括号
            char top = stk.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                stk.pop(); // 匹配成功，弹出栈顶元素
            } else {
                return false; // 不匹配
            }
        }
    }

    // 最后检查栈是否为空
    return stk.empty();
}

int main() {
    // 示例表达式
    string expression1 = "{[()]}";
    string expression2 = "{[(])}";
    string expression3 = "{[()]";

    // 输出示例表达式和检查结果
    cout << "表达式: " << expression1 << " 是否匹配: " << (isValidParentheses(expression1) ? "是" : "否") << endl;
    cout << "表达式: " << expression2 << " 是否匹配: " << (isValidParentheses(expression2) ? "是" : "否") << endl;
    cout << "表达式: " << expression3 << " 是否匹配: " << (isValidParentheses(expression3) ? "是" : "否") << endl;

    // ------------------ 堆栈的基本操作 ------------------
    stack<int> stk; // 创建一个整型堆栈

    // 压栈操作
    cout << "\n堆栈操作示例: " << endl;
    stk.push(10); // 压入10
    stk.push(20); // 压入20
    stk.push(30); // 压入30

    cout << "当前栈顶元素: " << stk.top() << endl; // 查看栈顶元素

    // 出栈操作
    stk.pop(); // 弹出栈顶元素
    cout << "弹出一个元素后，当前栈顶: " << stk.top() << endl;

    // 压入新元素
    stk.push(40);
    cout << "压入40后，当前栈顶: " << stk.top() << endl;

    // 检查栈是否为空
    cout << "栈是否为空: " << (stk.empty() ? "是" : "否") << endl;

    // 遍历堆栈的元素（注意：无法直接访问堆栈元素，只能弹出逐个遍历）
    cout << "堆栈内容（从栈顶到栈底）: ";
    while (!stk.empty()) {
        cout << stk.top() << " "; // 输出栈顶元素
        stk.pop();                // 弹出栈顶
    }
    cout << endl;

    return 0;
}
