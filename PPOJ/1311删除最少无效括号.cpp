#include "bits/stdc++.h"
#include"stack"
using namespace std;
const int maxsize=1e5+10;
int tag[maxsize];
stack<int> s;

void judge(string str)
{
	
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')
		{
			s.push(i);	
		}
		else{
			if(!s.empty())
			{
				tag[s.top()]=1;
				tag[i]=2;
				s.pop();
			}
			else tag[i]=0;
		}
	}
	for(int j=0;j<str.size();j++)
	{
		if(tag[j]==1)cout<<"(";
		if(tag[j]==2)cout<<")";
	}
}

int main()
{
	string s;
	cin>>s;
	judge(s);
	return 1;
}
