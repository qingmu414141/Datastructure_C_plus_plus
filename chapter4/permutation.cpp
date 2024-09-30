#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// 排列生成器
void permute(vector<int>& V, size_t k)
{
    if (k == V.size())
    {
        // 打印 V[0] 到 V[V.size() - 1];
        for (vector<int>::iterator it = V.begin(); it != V.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    else
        for (size_t i = k; i < V.size(); ++i)
        {
            // 交换 V[k] 与 V[i]
            std::swap(V[k], V[i]);
            permute(V, k + 1);
            // 交换 V[k] 与 V[i]
            std::swap(V[k], V[i]);
        }

}

int main()
{
    vector<int> V {1, 2, 3};
    permute(V, 0);
    return 0;
}