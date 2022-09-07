#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int a=-1)
	{
		data=a;
		left=right=NULL;
	}
};
class btree{
public:
	vector<int> stk;
	int res=0;
	btree() {}
	void insert(node *&root,node *&p)
	{
		int val;
		cin>>val;
		if(val==-1)
			root=NULL;
		else
		{
			root=new node(val);
			insert(root->left,root);
			insert(root->right,root);
		}
	}
	void houxu(node *root)
	{
		if(root==NULL)
			return ;
		stk.push_back(root->data);
		houxu(root->left);
		houxu(root->right);
		int temp=stk.size();
		if(temp-3>=0&&stk[temp-3]%2==0)
			res+=root->data;
		stk.pop_back();
	}
};
int main()
{
	int n;
	btree p;
	node *root=NULL;
	node *q=new node;
	p.insert(root,q);
	p.houxu(root);
	cout<<p.res<<endl;
	
	return 1;
}
