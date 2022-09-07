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
    L->next=L;
    return true;
}

int InsertLinkList(LinkList &L,ElemType n)
{
    LinkList p=L;int i=0;
    while(p->next!=L)
    {
        i++;p=p->next;
    }
    LinkList q=(LinkList)malloc(sizeof(LinkList));
    q->data=n;
    q->next=L;
    p->next=q;
    return i;
}

void PrintLinkList(LinkList &L)
{
    LinkList p=L->next;
    while (p!=L)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}

void merge(LinkList &L1,LinkList &L2)
{
    LinkList p=L1->next,pre1=L1,q=L1->next,pre2=L2;
    while (p!=L1)
    {
        p=p->next;
        pre1=pre1->next;
    }
    while (q!=L1)
    {
        q=q->next;
        pre2=pre2->next;
    }
    pre1->next=L2->next;
    pre2->next=L1;
}

signed main() {
    LinkList L1,L2;
    InitLinkList(L1);
    InitLinkList(L2);
    for(int i=0;i<10;i++)
        InsertLinkList(L1,(rand() % (10-1))+ 1);//1-10的随机数
    for(int i=0;i<10;i++)
        InsertLinkList(L2,(rand() % (10-1))+ 1);//1-10的随机数
    PrintLinkList(L1);
    puts("");
    PrintLinkList(L2);
    puts("");
    merge(L1,L2);
    PrintLinkList(L1);
    return 0;
}