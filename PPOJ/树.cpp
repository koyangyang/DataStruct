#include<bits/stdc++.h>
using namespace std;
struct BNode{
	int data;
	BNode *left;
	BNode *right;
	BNode(int a=-1)
	{
		data=a;
		left=right=NULL;
	}
};

class Btree{
public:
	int res=0;
	int height=0;
	btree() {}
	void insert(BNode *&B)
	{
		int val;
		cin>>val;
		if(val==-1)
			B=NULL;
		else
		{
			B=new BNode(val);
			insert(B->left);
			insert(B->right);
		}
	}
	void PreOrder(BNode *B,int h)
	{
		if(B)
		{
			if(h>height)
			{
				res=B->data;
				height=h;
			}
			PreOrder(B->left,h+1);
			PreOrder(B->right,h+1);
		}	
	}
	
};
int main()
{
	int n;
	Btree p;
	BNode *B=NULL;
	int pos=0;
	p.insert(B);
	p.PreOrder(B,1);
	cout<<p.res<<endl;
	return 1;
}
