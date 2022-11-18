#include "iostream"
#include"BST.h"
using namespace std;

Node* DeleteMoreX(Node *&T,int x)
{
	if (T)
	{
		if (T->data >= x)//比根节点大，说明根节点和右子树都比x大
		{
			Node *tmp=T;//删除根节点，直接返回左子树
			free(tmp);
			return DeleteMoreX(T->lson, x);
		}
		T->lson = DeleteMoreX(T->lson, x);
		T->rson = DeleteMoreX(T->rson, x);
		return T;
	}
	return NULL;
}

int main()
{
	Node *T;
	CreateBST(T,example,num);
	InOrder(T);
	puts("");
	DeleteMoreX(T,40);
	InOrder(T);
	return 0;
}
