#ifndef DS_LINKLIST_H
#define DS_LINKLIST_H
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
int example[] = {1, 2, 3, 4, 5, 6};
int num=6;
#endif //DS_LINKLIST_H
