//#include"bits/stdc++.h"
#include "iostream"
#include "LinkList.h"
using namespace std;

void ReverseNode(LinkList &L)
{
	LinkList p=L,q=L->next;
	if(q!=rear) ReverseNode(q);
	q->next=p;
}

void Reverse(LinkList &L)
{
	ReverseNode(L->next);
	L->next->next=NULL;
	L->next=rear;
}

int main()
{
	LinkList L;
	int n,t;
	cin>>n;
	int *a=new int(n);
	InitLinkList(L);
	for (int i = 0; i < n; ++i) {
		cin>>t;
		RearInsert(L,t);
	}
	Reverse(L);
	puts("");
	PrintLinkList(L);
	return 0;
}
