#include "iostream"
#include"LinkList.h"
using namespace std;

void Merge(Node *&L1,Node *&L2)
{
	Node *p=L1->next,*q=L2->next,*r=L1;
	L1->next;
	while(p&&q){
		Node *t;
		if(p->data>q->data)
		{
			t=new Node(q->data,NULL);
			q=q->next;
		}else{
			t=new Node(p->data,NULL);
			p=p->next;
		}
		r->next=t;
		r=t;
	}
	if(p)r->next=p;
	if(q)r->next=q;
}

int main()
{
	Node *L1,*L2;
	int a[]={1,3,5,7,9},b[]={2,4,6,8,10};
	Create(L1,a,5);
	Create(L2,b,5);
	Merge(L1,L2);
	Print(L1);
	return 0;
}
