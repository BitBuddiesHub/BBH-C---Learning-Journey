#include <iostream>
#include <stack>
#include <utility>   // for std::pair
#include <stdexcept>
#include <gmpxx.h>

/*
 * 朴素的 Ackermann 函数定义：
 *
 *   A(m, n) = 
 *     n+1                 if m = 0
 *     A(m-1, 1)           if m>0 && n=0
 *     A(m-1, A(m, n-1))   if m>0 && n>0
 *
 * 这里用 显式栈 + 迭代的方式 实现，可以应对“深度递归”。
 * 但不会进行任何溢出检查或范围限制，也不做任何小 m 特化。
 * 当输入巨大时，计算会极其缓慢，并占用海量内存。
 */

mpz_class ackermann_unlimited(const mpz_class &m_in, const mpz_class &n_in)
{
    // 显式维护一个栈，模拟函数递归调用
    // 栈元素是 (m, n)，均用 mpz_class 表示，确保无整数溢出
    std::stack<std::pair<mpz_class, mpz_class>> st;
    st.push({m_in, n_in});

    while (!st.empty()) {
        auto &top = st.top();
        mpz_class &mm = top.first;
        mpz_class &nn = top.second;

        if (mm == 0) {
            // A(0, n) = n + 1
            mpz_class result = nn + 1;

            // 弹出当前帧
            st.pop();

            if (st.empty()) {
                // 如果这是最外层调用，计算完成
                return result;
            } else {
                // 否则，把 result 赋给上一层的 n
                // 相当于上一层需要 A(m-1, [这里])
                st.top().second = result;
            }
        }
        else if (nn == 0) {
            // A(m, 0) = A(m-1, 1)
            // 只需把当前 (m, n) 改成 (m-1, 1) 即可
            mm = mm - 1;
            nn = 1;
        }
        else {
            // A(m, n) = A(m-1, A(m, n-1))
            // 需要先计算 A(m, n-1)，再用返回值做第二个参数
            // 因为要先算 A(m, n-1)，就先把 (m, n-1) 压栈
            // 同时把当前栈顶修改成 (m-1, 0) 占位，等A(m,n-1)出来后再回填
            mpz_class mm_bak = mm;
            mpz_class nn_bak = nn;
            
            // 把当前帧改成 (m-1, 0) ——因为后续会把结果塞进这里的 nn
            mm -= 1;
            nn = 0;

            // 另外压入 (m, n-1) 让它先计算
            st.push({ mm_bak, nn_bak - 1 });
        }
    }

    // 理论上不会到达这里，除非 m_in<0 或其它不合定义的输入
    // 为安全起见，可以 return 0 或抛异常
    // 这里选择抛出异常
    throw std::runtime_error("Ackermann: unexpected empty stack.");
}

int main()
{
    // 交互或硬编码测试
    // 下面示例：计算 A(3,4)（经典结果 125）和 A(4,1)（结果 65533）
    // 你也可以输入更大值，但要小心可能卡死或爆内存

    mpz_class m, n;
    std::cout << "Input m and n (non-negative): ";
    std::cin >> m >> n;

    try {
        mpz_class result = ackermann_unlimited(m, n);
        // .get_str() 得到十进制字符串
        std::cout << "A(" << m.get_str() << "," << n.get_str() << ") = " 
                  << result.get_str() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
