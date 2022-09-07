#include "iostream"
using namespace std;

typedef struct BNode{
	int data;
	struct BNode *lson,*rson;
}BNode,*BiTree;

int Insert_BST(BiTree &T,int x)
{
	if(T==NULL)
	{
		T=new BNode;
		T->data=x;
		T->lson=T->rson=NULL;
		return 1;
	}
	else{
		if(T->data==x) return 0;
		else if(T->data>x) return Insert_BST(T->lson,x);
		else return Insert_BST(T->rson,x);
	}
}

void Create_BST(BiTree &T,int a[],int n)
{
	T=NULL;
	for (int i = 0; i < n; ++i)
		Insert_BST(T,a[i]);
}

int flag=1;
int High(BiTree B)
{
	if(B==NULL) return 0;
	int left=High(B->lson);
	int right=High(B->rson);
	if(abs(left-right)>1) flag=0;
	return max(left,right)+1;
}

int main()
{
	BiTree T;
	int a[]={54,20,66,40,79,58};//将要进入二叉排序树的元素值
	Create_BST(T,a,6);
	High(T);
	cout<<flag;
	return 0;
}
