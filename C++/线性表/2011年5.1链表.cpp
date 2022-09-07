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

//计算一个链表的长度
int CountLength(LinkList L)
{
    int count=0;
    LinkList p=L->next;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

signed main() {
    LinkList L;
    InitLinkList(L);
    for(int i=0;i<1011;i++)
        InsertLinkList(L,(rand() % (10-1))+ 1);//1-10的随机数
    cout<<CountLength(L)<<endl;
    return 0;
}