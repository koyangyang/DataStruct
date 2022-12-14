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

int findMid(LinkList L)
{
    LinkList p=L->next,q=L->next;
    while(q!=NULL)
    {
        q=q->next;
        p=p->next;
        if(q!=NULL)
            q=q->next;
    }
    return p->data;
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

int main() {
    int n;
    LinkList L;
    InitLinkList(L);
    for(int i=0;i<10;i++)
        InsertLinkList(L,(rand() % (10-1))+ 1);//1-10ηιζΊζ°
    PrintLinkList(L);
    puts("");
    cout<<findMid(L);
    return 0;
}