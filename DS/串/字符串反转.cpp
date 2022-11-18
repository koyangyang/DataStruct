#include "iostream"
#include"algorithm"
#include"stack"
using namespace std;

void Reverse(string s)
{
	stack<int> stk;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(') stk.push(i);
		else if(s[i]==')')
		{
			int l=stk.top();stk.pop();
			reverse(s.begin()+l,s.begin()+i+1);
		}
	}
	string ans;
	for(int i=0;i<s.size();i++){
		if(s[i]!='('&&s[i]!=')') ans+=s[i];
	}
	cout<<ans;
}

int main()
{
	string s;
	cin>>s;
	Reverse(s);
	return 0;
}
