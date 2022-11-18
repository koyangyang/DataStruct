#include "iostream"
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList rear=NULL;

bool InitLinkList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(L==NULL) return false;
    L->next=NULL;
    rear=L;
    return true;
}

void RearInsert(LinkList &L,int n)
{
    LinkList p=L;int i=0;
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=n;
    q->next=NULL;
    if(rear==L)
    {
        p->next=q;
        rear=p->next;
    }
    else{
        rear->next=q;
        rear=q;
    }
}

void HeadInsert(LinkList &L,int n)
{
    LinkList p=L->next;int i=0;
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=n;
    if(p==NULL)
        q->next=NULL;
    else q->next=p;
    L->next=q;
}

void PrintLinkList(LinkList &L)
{
    LinkList p=L->next;
    while (p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}

int i=0;
void reverse(LinkList head)
{
	LinkList p=head->next;
	if ((p==NULL)||(p->next==NULL)) return;
	else
	{
		i++;
		reverse(p);//递归部分
		p->next->next = p;
		p->next = NULL;//最关键
	}
	i--;
	if (i==0)
	{
		head->next = rear;//使头指针指向末尾指针
	}
}
}

int main()
{
	InitLinkList(l);
	int t;
	while(cin>>t){
		RearInsert(l,t);
	}
	PrintLinkList(l);
    puts("");
    reverse(L);
    PrintLinkList(L);
	return 0;
}
