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

void Delete(LinkList &L,int min,int max)
{
    LinkList pre=L,p=L->next,q;
    while(p!=NULL)
    {
        if(p->data>=min&&p->data<=max)
        {
            q=p;
            p=p->next;
            pre->next=p;
            //free(q);
        } else
        {
            p=p->next;
            pre=pre->next;
        }
    }
}

signed main() {
    LinkList L;
    InitLinkList(L);
    for(int i=0;i<20;i++)
        InsertLinkList(L,i);//1-10的随机数
    PrintLinkList(L);
    puts("");
    Delete(L,5,9);
    PrintLinkList(L);
    return 0;
}