#include "iostream"
using namespace std;
struct Node
{
	Node(int x, struct Node *next) : data(x), next(next) {}
	int data;
	struct Node *next;
};
void Create(Node *&L, int a[], int n)
{
	L = new Node(-1, NULL);
	Node *r = L;
	for (int i = 0; i < n; i++)
	{
		Node *t = new Node(a[i], NULL);
		r->next = t;
		r = t;
	}
}
void Print(Node *L)
{
	Node *p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
//void SelectSort(Node *&L)
//{
//	Node *h=L->next,*p,*q,*r,*s;
//	L->next=NULL;
//	while(h)
//	{
//		p=s=h;q=r=NULL;
//		while(p)
//		{
//			if(p->data>s->data){s=p;r=q;}
//			q=p;p=p->next;
//		}
//		if(s==h)h=h->next;
//		else r->next=s->next;
//		s->next=L->next;
//		L->next=s;
//	}
//}
void SelectSort(Node *&L)
{
	Node *h=L->next,*p,*q,*r,*s;
	L->next=NULL;
	while(h)
	{
		p=s=h;q=r=NULL;//s指向最大结点，r指向最大结点的前一个结点
		while(p)//p是工作结点
		{
			if(p->data>s->data){s=p;r=q;}
			q=p;p=p->next;//q是指向工作结点的前驱结点
		}
		if(s==h)h=h->next;
		else r->next=s->next;
		s->next=L->next;
		L->next=s;
	}
}
main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	Node *L;
	Create(L, a, 6);
	SelectSort(L);
	Print(L);
}
