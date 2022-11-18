#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *lson;
	node *rson;
	node(int a=-1)
	{
		data=a;
		lson=rson=NULL;
	}
};
class btree{
public:
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
			insert(root->lson,root);
			insert(root->rson,root);
		}
	}
	void preorder(node* t)
	{
		if(t)
		{
			cout<<t->data;
			preorder(t->lson);
			preorder(t->rson);
		}
	}
};
int main()
{
	int n;
	btree p;
	node *root=NULL;
	node *q=new node;
	p.insert(root,q);
	p.preorder(root);
	return 1;
}
