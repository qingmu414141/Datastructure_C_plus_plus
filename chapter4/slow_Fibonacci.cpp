#include <iostream>

using std::cout;
using std::endl;

uint64_t Fibonacci(unsigned int n)
{
    // 返回值类型取 uint64_t 是为了避免溢出
    if (n <= 1)
        return n;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    // 为后文分析方便写成上述形式。更简洁的表述是条件表达式：
    // return (n <= 1) ? n : Fibonacci(n - 1) + Fibonacci(n - 2)
}

void Fibonacci_sequence(unsigned int m)
{
    for (unsigned int i = 0; i < m; ++i)
        cout << Fibonacci(i) << ' ' << i << endl;
}
