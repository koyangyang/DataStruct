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

void SelectSort(LinkList &L)
{
    LinkList h = L->next, p, q, r, tmp;
    while (h)
    {
        int min = h->data;
        p = h, q = h->next;
        while (p)
        {
            if (q->data < min)
            {
                min = q->data;
                r = p;
            }
            p = p->next;
            q = q->next;
        }
        if (r != p)
        {
            tmp = r->next;
            r->next = tmp->next;
            tmp->next = L->next;
            L->next = tmp;
        }
    }
}

int main()
{
    LinkList L;
    InitLinkList(L);
    int n,t;
    cin >> t;
    while(n--)
    {
        cin >> t;
        RearInsert(L, t);
    }
}