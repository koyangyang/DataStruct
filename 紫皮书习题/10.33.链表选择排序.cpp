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

void HeadInsert(LinkList &L, int n)
{
    LinkList p = L->next;
    int i = 0;
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = n;
    if (p == NULL)
        q->next = NULL;
    else
        q->next = p;
    L->next = q;
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

void SelectSort(LinkList &L)
{
    LinkList p = L->next, tmp = NULL;
    while (p)
    {
        LinkList q = p->next;
        int min = p->data;
        while (q)
        {
            if (q->data < min)
            {
                min = q->data;
                tmp = q;
            }
            p = p->next;
        }
        tmp->data = p->data;
        p->data = min;
        p = p->next;
    }
}

int main()
{
    int a[] = {54, 20, 66, 40, 28, 79, 58};
    LinkList L;
    InitLinkList(L);
    for (int i = 0; i < 7; i++)
        RearInsert(L, a[i]);
    PrintLinkList(L);
    SelectSort(L);
    PrintLinkList(L);
    return 0;
}