#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    // 定义一个初始长度为10的向量V，可用位置数为10.
    vector<int> V(10);
    // 下标 i（注意是 size_t型）从 0 到 V.size() - 1对 V 中每个元素赋值 i（已转 int 型）.
    // 应保证向量 V 中实有元素个数恒为V.size()，即便短暂失效也要快速复位.
    for (size_t  i = 0; i < V.size(); ++i)
        V[i] = static_cast<int>(i);     // 向量的下标用法与数组相同.
    // 使用迭代器 iter 对向量 V 中每个元素赋值 1，要体会 begin()和 end()的用法.
    // iter为 vector<int>::iterator型，为使代码更简洁,
    // 可用 auto 关键字配合赋值语句自动获取其类型.
    // 不妨思考iter - V.begin()的值.
    for (auto iter = V.begin(); iter != V.end(); ++iter)
        *iter = 1;
    // 也可以使用基于范围的 for 循环完成赋值，遍取 V 中的元素 X(引用方式).
    for (auto &x : V)
        x = 1;
    // 在向量末尾加入 1000 个 2，适用于大量重复数据的情况.
    V.resize(V.size() + 1000, 2);
    // 在向量末尾加入 3，若要多次使用最好提前预留容量.
    V.push_back(3);
    // 若 V 不为空，则持续打印 V 的末尾元素并删除之.
    while (!V.empty())
    {
        cout << V.back() << endl;   // 打印 V 的末尾元素.
        V.pop_back();               // 删除 V 的末尾元素.
    }

    // 定义一个长度为 5 的向量 A，初始元素全为 3.
    vector<int> A(5, 3);
    // 由于向量的特殊性，迭代器还有另一种用法.
    auto iter = A.begin();
    for (size_t i  = 0; i < A.size(); ++i)
        *(iter + i) *= 2;       // 相当于 A[i] *= 2
    
    // 对向量 X 使用（直接）列表初始化.
    vector<int> X {4, 2, 1, 5, 3};
    // 更像 C 语言形式的传统写法是复制列表初始化，但效率稍低:
    // vector<int> X = {4, 2, 1, 5, 3}

    // 此时向量长度分别为0，5, 5.
    cout << V.size() + A.size() + X.size() << endl;

}
