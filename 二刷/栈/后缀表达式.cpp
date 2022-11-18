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
bool isOp(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return true;
	else
		false;
}
void topost(string s)
{
	stack<char> stk2;
	string post = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (isOp(s[i]))
		{
			while (!stk2.empty() && getPrior(stk2.top()) >= getPrior(s[i]))
			{
				char x = stk2.top();
				stk2.pop();
				if (x == '(' && s[i] == ')')
					break;
				post.push_back(x);
			}
			if (s[i] != ')')
				stk2.push(s[i]);
		}
		else
		{
			post.push_back(s[i]);
		}
	}
	while (!stk2.empty())
	{
		char x = stk2.top();
		stk2.pop();
		post.push_back(x);
	}
	cout << post << endl;
}

int main()
{
	string s = "(a+b)*c/d";
	topost(s);
	return 0;
}