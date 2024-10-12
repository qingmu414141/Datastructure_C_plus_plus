#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;
using std::cin;
using std::cout;
using std::endl;

bool validator(const string& brackets)
{
    stack<char> S;  // 也可用字符串存储
    for (size_t i = 0; i < brackets.size(); ++i)
        switch (brackets[i])
        {
            case '(':
                S.push(brackets[i]);
                break;
            case ')':
                if (S.empty() || S.top() != '(')
                    return false;
                S.pop();
                break;
            case '[':
                S.push(brackets[i]);
                break;
            case ']':
                if (S.empty() || S.top() != '[')
                    return false;
                S.pop();
                break;
            case '{':
                S.push(brackets[i]);
                break;
            case '}':
                if (S.empty() || S.top() != '{')
                    return false;
                S.pop();
                break;
            default:
                return false;
        }
    return S.empty();
}

int main()
{
    string brackets;
    cin >> brackets;
    cout << (validator(brackets) ? "匹配" : "不匹配或存在非括号字符")
        << endl;
    return 0;
}