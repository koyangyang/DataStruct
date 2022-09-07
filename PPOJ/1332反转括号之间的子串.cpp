#include "bits/stdc++.h"
#include"stack"
using namespace std;

void solution(string &s)
{
	stack<int> stk;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')
			stk.push(i);
		if(s[i]==')')
		{
			int p=stk.top();stk.pop();
			reverse(s.begin()+p,s.begin()+i);
		}	
	}
	for(int i=0;i<s.length();i++){
		if(s[i]!='('&&s[i]!=')')
			cout<<s[i];
	}
}

int main()
{
	string s;
	cin>>s;
	solution(s);
	return 0;
}
