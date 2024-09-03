#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::cout;
using std::copy;
using std::ostream_iterator;

int main()
{
    vector<int> V {2, 0, 2, 4};

    // 方案1：使用下标.
    // 此处 size_t 尽量不要用 int 代替.
    for (size_t i = 0; i < V.size(); ++i)
        cout << V[i] << ' ';
    
    // 方案2：使用 vector<int>::const_iterator 型常量迭代器 citer,
    // 注意常量迭代器只读不写，相当于加了 const 约束.
    // 这里特别以 cbegin 和 cend 区别于 begin 和 end, 从而保证 citer 是常量迭代器.
    for (auto citer = V.cbegin(); citer != V.cend(); ++citer)
        cout << *citer << ' ';
    
    // 方案3: 基于范围的 for 循环, 由于不会改动向量, 所以可加 const 约束.
    for (const auto& x: V)
        cout << x << ' ';
    
    // 由于存储的是 int 元素, 也可以用复制的方式 for (auto x: V), 
    // 将 V 中元素逐个复制到 x 中再打印, 但是不适合体积较大的元素

    // 方案4: 使用 copy 算法
    // 必须包含 algorithm 和 iterator 头文件
    // 另外空格要用字符串形式 " " 而不能用字符形式 ' '.
    copy(V.cbegin(), V.cend(), ostream_iterator<int>(cout, " "));
    
    return 0;
}