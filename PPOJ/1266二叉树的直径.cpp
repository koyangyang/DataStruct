//对于每个节点而言，其最大距离是左子树的最深点和右子树的最深点的距离，遍历树中每个点更新该距离即可。
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
	int flag=0;
	int res=0;
	btree() {}
	void insert(node *&root)
	{
		int val;
		cin>>val;
		if(val==-1)
			root=NULL;
		else
		{
			root=new node(val);
			insert(root->left);
			insert(root->right);
		}
	}
	void xianxu(node *root)
	{
		if(root==NULL)
			return ;
		int l=height(root->left);
		int r=height(root->right);
		res=max(res,l+r);
		xianxu(root->left);
		xianxu(root->right);
	}
	int height(node *root)
	{
		if(root==NULL) return 0;
		int l=height(root->left);
		int r=height(root->right);
		return 1+max(l,r);
	}
};
int main()
{
	int n;
	btree p;
	node *root=NULL;
	int pos=0;
	p.insert(root);
	p.xianxu(root);
	cout<<p.res<<endl;
	return 1;
}
