//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

bool InitLinkList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LinkList));
    if(L==NULL) return false;
    L->next=NULL;
    return true;
}

int InsertLinkList(LinkList &L,ElemType n)
{
    LinkList p=L;int i=0;
    while(p->next!=NULL)
    {
        i++;p=p->next;
    }
    LinkList q=(LinkList)malloc(sizeof(LinkList));
    q->data=n;
    q->next=NULL;
    p->next=q;
    return i;
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

void deleteNode(LinkList L,int key)
{
    LinkList q=L;
    while(q->next!=NULL)
    {
        if(q->next->data==key){
            if(q->next->next!=NULL)
            {
                LinkList p=q->next->next;
                q->next->data=p->data;
                q->next->next=p->next;
                free(p);
            }
            else q->next=NULL;
        }
       q=q->next;
    }
}

signed main() {
    LinkList L;
    InitLinkList(L);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int n;
        cin>>n;
        InsertLinkList(L,n);
    }
    PrintLinkList(L);
    puts("");
    deleteNode(L,)
    return 0;
}