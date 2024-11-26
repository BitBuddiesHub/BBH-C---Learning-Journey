#include <iostream> // 包含标准输入输出库
using namespace std;

// 递归实现汉诺塔
// 参数说明：
// n - 当前需要移动的盘子数
// from - 起始柱子的标识
// to - 目标柱子的标识
// aux - 辅助柱子的标识
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        // 基本情况：如果只剩下一个盘子，直接将其从起始柱移动到目标柱
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return; // 结束当前递归
    }

    // Step 1: 将 n-1 个盘子从起始柱 (from) 移到辅助柱 (aux)，目标柱 (to) 作为辅助
    hanoi(n - 1, from, aux, to);

    // Step 2: 将第 n 个（最大的）盘子从起始柱 (from) 移到目标柱 (to)
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Step 3: 将 n-1 个盘子从辅助柱 (aux) 移到目标柱 (to)，起始柱 (from) 作为辅助
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n; // 定义圆盘的数量
    cout << "Enter the number of disks: "; // 提示用户输入圆盘数量
    cin >> n; // 获取用户输入

    // 调用 hanoi 函数，将所有盘子从 A 移到 C，B 作为辅助柱
    hanoi(n, 'A', 'C', 'B');

    return 0; // 返回 0 表示程序正常结束
}
