#include "iostream"
#include"BST.h"
using namespace std;

int solve(Node *T,int &pre)
{
	if(T)
	{
		solve(T->rson,pre);
		pre=pre+T->data;
		solve(T->lson,pre);
	}
	return 0;
}

int main()
{
	Node *T;
	int pre=0;
	int a[]={4,6,7,8,5,1,2,3,0};
	CreateBST(T,a,9);
	solve(T,pre);
	cout<<pre;
	return 0;
}
