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

void insert(LinkList &L,int key)
{
    LinkList p=L->next;
    LinkList q=(LinkList)malloc(sizeof(LNode));
    q->data=key;
    L->next=q;
    if(p==NULL) q->next=NULL;
    else q->next=p;
}

int DeleteNode(LinkList &L,int i)
{
    int j=1;LinkList p=L->next;
    while(p!=NULL&&j<i-1)
    {
        j++;
        p=p->next;
    }
    if(j==i-1){
        if(p->next->next!=NULL) p->next=p->next->next;
        else p->next=NULL;
    }
    return 1;
}

int main() {
    LinkList L;
    InitLinkList(L);
    for (int i = 0; i < 10; ++i)
        insert(L,i);
    DeleteNode(L,6);
    LinkList p=L->next;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}