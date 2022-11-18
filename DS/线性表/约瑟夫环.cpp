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
	L = new Node(-1, L);
	Node *r = L;
	for (int i = 0; i < n; i++)
	{
		Node *t = new Node(a[i], L->next);
		r->next = t;
		r = t;
	}
}
void Print(Node *L)
{
	Node *p = L->next;
	while (p->next!=L->next)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int example[] = {1, 2, 3};
int num=3;
void ysfh(Node *L,int k)
{
	Node *p=L->next,*r;
	while(p->next!=p)
	{
		for(int i=0;i<k-1;i++){
			r=p;
			p=p->next;
		}
		cout<<"kill "<<p->data<<endl;
		r->next=p->next;
		p=p->next;
	}
	cout<<p->data;
}
int main()
{
	Node *L;
	Create(L,example,num);
	ysfh(L,2);
}
