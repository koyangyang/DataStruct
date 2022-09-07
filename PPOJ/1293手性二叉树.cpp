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
	bool flag=0;
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
	void xianxu(node *root)
	{
		if(root==NULL||flag==1)
			return ;
		if(!judge(root->left,root->right))
		{
			flag=1;
			return ;
		}
		xianxu(root->left);
		xianxu(root->right);
	}
	bool judge(node *root1,node *root2)
	{
		if(root1==NULL&&root2==NULL)
			return true;
		else if(root1==NULL||root2==NULL||root1->data!=root2->data)
			return false;
		return judge(root1->left,root2->right)&&judge(root1->right,root2->left);
	}
};
int main()
{
	int n;
	btree p;
	node *root=NULL;
	node *q=new node;
	p.insert(root,q);
	if(root!=NULL)
	{
		if(p.judge(root->left,root->right))
			cout<<"yes";
		else
			cout<<"no";
	}
	else
		cout<<"yes";
	return 1;
}
