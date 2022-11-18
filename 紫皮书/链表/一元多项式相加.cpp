#include "iostream"
#include "stack"
using namespace std;

int getPrior(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    else
        return -1;
}

int cal(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '/')
        return a - b;
    if (c == '/')
        return a / b;
    if (c == '*')
        return a * b;
    else
        return 1;
}

int caluate(string s)
{
    int len = s.size();
    stack<int> stk1;
    stack<char> stk2;
    for (int i = 0; i < len; i++)
    {
        if (s[i] > '0' && s[i] < '9')
            stk1.push(s[i] - '0');
        else
        {
            if (s[i] == '(')
                stk2.push('(');
            else
            {
                if (s[i] == ')')
                {
                    while (stk2.top() != '(')
                    {
                        int b = stk1.top();
                        stk1.pop();
                        int a = stk1.top();
                        stk1.pop();
                        char c = stk2.top();
                        stk2.pop();
                        stk1.push(cal(a, b, c));
                    }
                }
                else
                {
                    while (!stk2.empty() && getPrior(s[i]) < getPrior(stk2.top()))
                    {
                        int b = stk1.top();
                        stk1.pop();
                        int a = stk1.top();
                        stk1.pop();
                        char c = stk2.top();
                        stk2.pop();
                        stk1.push(cal(a, b, c));
                    }
                    stk2.push(s[i]);
                }
            }
        }
        while (!stk2.empty())
        {
            int b = stk1.top();
            stk1.pop();
            int a = stk1.top();
            stk1.pop();
            char c = stk2.top();
            stk2.pop();
            stk1.push(cal(a, b, c));
        }
    }
    cout << stk1.top();
}

int main()
{
    string s;
    cin >> s;
    caluate(s);
    return 0;
}