#include <iostream>
#include <set>

using std::set;
using std::cout;
using std::endl;

int main()
{
    set<int> X {3, 4, 1};
    set<int>::iterator p = X.begin();
    ++p;
    cout << *p << endl;
    return 0;
}