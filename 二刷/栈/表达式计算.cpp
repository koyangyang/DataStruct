#include "iostream"
#include "stack"
using namespace std;

int getPrior(char x)
{
	if (x == '+' || x == '-')
		return 2;
	if (x == '*' || x == '/')
		return 3;
	if (x == '(')
		return 1;
	if (x == ')')
		return -1;
}

int cal(int a, int b, char x)
{
	if (x == '+')
		return a + b;
	if (x == '*')
		return a * b;
	if (x == '-')
		return a - b;
	if (x == '/')
		return a / b;
	return 1;
}

int caluate(string s)
{
	stack<int> stk1;
	stack<char> stk2;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > '0' && s[i] < '9')
			stk1.push(s[i] - '0');
		else
		{
			if (s[i] == '(')
				stk2.push(s[i]);
			else
			{
				while (!stk2.empty() && getPrior(s[i]) < getPrior(stk2.top()))
				{
					char x = stk2.top();
					stk2.pop();
					if (x == '(' && s[i] == ')')
						break;
					int b = stk1.top();
					stk1.pop();
					int a = stk1.top();
					stk1.pop();
					stk1.push(cal(a, b, x));
				}
				if (s[i] != ')')
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
		char x = stk2.top();
		stk2.pop();
		stk1.push(cal(a, b, x));
	}
	return stk1.top();
}

int main()
{
	string s = "(1+1)*2+1+1";
	cout << caluate(s);
	return 0;
}