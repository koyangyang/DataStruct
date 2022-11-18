#include "iostream"
using namespace std;
void Post(char R[])
{
	int top=-1,i,V[300];
	V['(']=0,V['+']=V['-']=1,V['*']=V['/']=2;
	char stk[100];
	for(i=0;R[i]!='\0';i++)
	{
		if(R[i]>='a'&&R[i]<='z') cout<<R[i];
		else if(R[i]=='(') stk[++top]=R[i];
		else if(R[i]==')')
		{
			while(stk[top]!='(')cout<<stk[top--];
			top--;
		}
		else{
			while(top!=-1&&V[R[i]]<=V[stk[top]])
			{
				cout<<stk[top--];
			}
			stk[++top]=R[i];
		}
	}
	while(top!=-1)cout<<stk[top--];
}
int main()
{
	char R[300];
	scanf("%s",R);
	Post(R);
	return 0;
}
