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

void InsertSort(LinkList &L)
{
    LinkList p = L->next;
    if(p)
        p = p->next;
        else
            return;
    while (p)
    {
        LinkList q = L->next;
        
    }
    
}

int main()
{
    int a[] = {54, 20, 66, 40, 28, 79, 58};
    LinkList L;
    InitLinkList(L);
    for (int i = 0; i < 7;i++)
        RearInsert(L, a[i]);
    PrintLinkList(L);
    return 0;
}