#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

void convertor(int n, int b, string& result)
{
    string d2c = "0123456789ABCDEF";
    result = "";                // 清空 result
    stack<char> S;              // 也可使用字符串直接实现
    if (n < 0)                  // 处理负数情况
    {
        result += "-";
        n = -n;
    }
    do {
        S.push(d2c[n % b]);     // 类似向量的映射功能
        n /= b;
    } while (n != 0);
    while (!S.empty())
    {
        result += S.top();
        S.pop();
    }
}


int main()
{
    int n = 1000;
    int b = 8;
    string result = "";
    convertor(n, b, result);
    cout << result << endl;
}