#include "iostream"
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList rear = NULL;

bool InitLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    rear = L;
    return true;
}

void RearInsert(LinkList &L, int n)
{
    LinkList p = L;
    int i = 0;
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = n;
    q->next = NULL;
    if (rear == L)
    {
        p->next = q;
        rear = p->next;
    }
    else
    {
        rear->next = q;
        rear = q;
    }
}

void PrintLinkList(LinkList &L)
{
    LinkList p = L->next;
    while (p != NULL)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}

int main()
{
    LinkList L1, L2;
    
    return 0;
}