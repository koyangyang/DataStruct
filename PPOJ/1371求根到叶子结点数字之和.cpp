#include "iostream"
#include"BST.h"
using namespace std;

int res=0;
void soluion(BiTree T,int n)
{
	if(T)
	{
		res+=T->data*n;
		soluion(T->lson,n*10);
		soluion(T->rson,n*10);
	}
}

int main()
{
	BiTree T;
	Create_BST(T,example,6);
	soluion(T,1);
	cout<<res;
	return 0;
}
