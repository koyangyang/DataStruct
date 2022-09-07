#include "iostream"
using namespace std;

typedef struct LNode {
    int x;
    int y;
    struct LNode *next;
}LNode,*LinkList;

bool InitLinkList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(L==NULL) return false;
    L->next=NULL;
    return true;
}

int InsertLinkList(LinkList &L,int x,int y)
{
    LinkList p=L;int i=0;
    while(p->next!=NULL)
    {
        i++;p=p->next;
    }
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->x=x;
    q->y=y;
    q->next=NULL;
    p->next=q;
    return i;
}

void PrintLinkList(LinkList &L)
{
    LinkList p=L->next;
    while (p!=NULL)
    {
        cout<<p->y<<" "<<p->x<<endl;
        p=p->next;
    }
}

void Merge(LinkList &LA,LinkList &LB)
{
    LinkList p=LA->next,q=LB->next;
    LinkList LC=LA,l=LC;
    while (p&&q)
    {
        if(p->y==q->y)
        {
            p->x+=q->x;
            l->next=p;
            p=p->next;
            q=q->next;
        }
        else if(p->y<q->y)
        {
            l->next=p;
            p=p->next;
        }
        else {
            l->next=q;
            q=q->next;
        }
        l=l->next;
    }
    if(p) l->next=p;
    if(q) l->next=q;
}

int main() {
    LinkList LA,LB;
    InitLinkList(LA);
    InitLinkList(LB);
    int m,n;
    cin>>m>>n;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>y>>x;
        InsertLinkList(LA,x,y);
    }
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>y>>x;
        InsertLinkList(LB,x,y);
    }
    Merge(LA,LB);
    PrintLinkList(LA);
    return 1;
}