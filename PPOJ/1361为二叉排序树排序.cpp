//以为是在递归遍历是同时进行检查，结果是搞出两个数列来合并，那确实是道水题。
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
	vector<int> res;
public:
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
	void zhongxu(node *root)
	{
		if(root==NULL)
			return ;
		zhongxu(root->left);
		res.push_back(root->data);
		zhongxu(root->right);
	}
	void print()
	{
		sort(res.begin(),res.end());
		for(auto num:res)
		{
			cout<<num<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	int n;
	btree p;
	node *root1=NULL;
	node *root2=NULL;
	p.insert(root1);
	p.insert(root2);
	p.zhongxu(root1);
	p.zhongxu(root2);
	p.print();
	return 1;
}
