#include "iostream"
#include"queue"
#include"BST.h"
using namespace std;

void Delete(Node *&B,int x)
{
	queue<Node*> q;
	q.push(B);
	while(!q.empty()){
		Node *t=q.front();q.pop();
		if(t->lson)
		{
			if(t->lson->data==x&&!t->lson->lson&&!t->lson->rson)
				t->lson=NULL;
			else
				q.push(t->lson);
		}
		if(t->rson)
		{
			if(t->rson->data==x&&!t->rson->lson&&!t->rson->rson)
				t->rson=NULL;
			else
				q.push(t->rson);
		}
	}
}

int main()
{
	Node *B;
	CreateBST(B,example,num);
	Delete(B,11);
	InOrder(B);
	return 0;
}
