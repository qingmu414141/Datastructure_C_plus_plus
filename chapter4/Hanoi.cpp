#include <iostream>

using std::cout;
using std::endl;

void Hanoi(unsigned int n, char source, char other, char destination)
{
    // 对 n <= 0 情况无任何操作
    if (n > 0)
    {
        Hanoi(n - 1, source, destination, other);
        cout << "move " << source << " to " << destination << endl;
        Hanoi(n -1, other, source, destination);    
    }
}

int main()
{
    Hanoi(5, 'A', 'B', 'C');
}