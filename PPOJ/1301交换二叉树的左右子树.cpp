#include "iostream"
#include"BST.h"
using namespace std;

BiTree exchange(BiTree &T)
{
	if(T)
	{
		T->rson=exchange(T->rson);
		T->lson=exchange(T->lson);
		swap(T->lson,T->rson);
		return T;
	}
	return NULL;
}

int main()
{
	BiTree B;
	int a[]={54,20,66,40,28,79,58};
	Create_BST(B,a,7);
	exchange(B);
	InOrder(B);
	return 0;
}
