//我的思路是类似与找二叉树祖先，两次后序遍历把对应的祖先分别装到栈里。然后统一高度往上搜索即可，一定能找到根节点作为祖先，这样比较麻烦。
//答案思路是先序判断当前节点是否为对应的祖先，如果节点值为两者之一，那么说明对应节点可能是最近祖先，如果为空说明没找到，一定不是，然后依次往下搜索，如果一个节点的左右子树里分别找到了两个值，说明该节点为最近祖先，否则两个值在同一颗子树中，则其最近祖先为搜索对应子树出来的结果。
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
	int height[2];
	vector<int> stk[2];
	int temp=-1;
	int flag=0;
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
	node *the_ancestor(node *root,int val1,int val2)
	{
		if(root==NULL||root->data==val1||root->data==val2)
			return root;
		node *l=the_ancestor(root->left,val1,val2);
		node *r=the_ancestor(root->right,val1,val2);
		if(l&&r)
			return root;
		else
			return l==NULL? r:l;
	}
	void xianxu(node *root,int x,int idx)
	{
		if(root==NULL||flag==1)
			return;
		temp++;
		if(root->data==x)
		{
			height[idx]=temp;
		}
		stk[idx].push_back(root->data);
		if(root->data==x)
		{
			flag=1;
			return ;
		}
		xianxu(root->left,x,idx);
		xianxu(root->right,x,idx);
		temp--;
		if(flag!=1)
			stk[idx].pop_back();
	}
	void mfind()
	{
		if(height[0]<height[1])
		{
			while(height[1]>height[0])
			{
				stk[1].pop_back();
				height[1]--;
			}
		}
		else if(height[0]>height[1])
		{
			while(height[0]>height[1])
			{
				stk[0].pop_back();
				height[0]--;
			}
		}
		while(stk[0][height[0]]!=stk[1][height[1]])
		{
			height[0]--;
			height[1]--;
		}
		cout<<stk[0][height[0]]<<endl;
	}
	
};
int main()
{
	int n;
	btree p;
	node *root=NULL;
	int pos=0;
	p.insert(root);
	int val1,val2;
	cin>>val1>>val2;
	node *k=p.the_ancestor(root,val1,val2);
	cout<<k->data<<endl;
	return 1;
}
