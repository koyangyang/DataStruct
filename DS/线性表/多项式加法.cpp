#include "iostream"
using namespace std;
struct Node
{
	Node(int c,int x, struct Node *next) : c(c),x(x), next(next) {}
	int x,c;
	struct Node *next;
};
void Create(Node *&L, int a[],int b[], int n)
{
	L = new Node(-1,-1, NULL);
	Node *r = L;
	for (int i = 0; i < n; i++)
	{
		Node *t = new Node(a[i],b[i], NULL);
		r->next = t;
		r = t;
	}
}
void Print(Node *L)
{
	Node *p = L->next;
	while (p)
	{
		cout << p->c<<"x^"<<p->x << " ";
		p = p->next;
	}
}

void Add(Node *&L1,Node *&L2)
{
	Node *p=L1->next,*q=L2->next,*t=L1,*tmp;
	L1->next=NULL;
	while(p&&q){
		if(p->x==q->x)
		{
			tmp=new Node(p->c+q->c,p->x,NULL);
			t->next=tmp;
			t=tmp;
			p=p->next;
			q=q->next;
		}
		else{
			if(p->x>q->x)
			{
				t->next=q;
				q=q->next;
				t=t->next;
				t->next=NULL;
			}
			else{
				t->next=p;
				p=p->next;
				t=t->next;
				t->next=NULL;
			}
		}
	}
}
int main()
{
	int a[]={1,2,3,4};
	int b[]={1,3,5,7};
	int c[]={5,6,7,8};
	int d[]={1,4,6,8};
	Node *T,*B;
	Create(T,a,b,4);
	Create(B,c,d,4);
	Add(T,B);
	Print(T);
	return 0;
}
