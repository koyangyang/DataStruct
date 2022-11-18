#include<bits/stdc++.h>
using namespace std;

typedef struct tnode{
	int data;
	struct tnode *left = NULL;
	struct tnode *right = NULL;
}tnode,*tpoint;

tpoint buildtree()//先序建树1
{
	int i;
	scanf("%d",&i);
	if(i==-1)return NULL;
	tpoint T = new tnode;
	T->data = i;
	T->left = buildtree();
	T->right = buildtree();
	return T;
}

int f = 0;

bool ancestor(tpoint &T,int x,int y)
{
	if(T==NULL||f==1)return false;
	bool L,R;
	L = ancestor(T->left,x,y);
	R = ancestor(T->right,x,y);
	if((T->data==x||T->data==y)&&f==0)//两点父子关系
	{
		if(L||R)
		{
			f = 1;
			cout<<T->data;
		}
		else return true;
	}
	if(L&&R&&f==0)//两点非父子关系
	{
		f = 1;
		cout<<T->data;
	}
	return L||R;
}

int main(){
	tpoint T = buildtree();
	int x,y;
	cin>>x>>y;
	ancestor(T,x,y);
	return 0;
}
