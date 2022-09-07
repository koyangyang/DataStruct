#include"iostream"
#include"BST.h"
using namespace std;

int sum=0;
void In(BiTree &B)
{
	if(B!=NULL)
	{
		In(B->rson);
		sum+=B->data;
		B->data=sum;
		In(B->lson);
	}
}

int main()
{
	BiTree T;
	int a[]={54,20,66,40,28,79,58};
	Create_BST(T,a,7);
	In(T);
	InOrder(T);
	return 0;
}
