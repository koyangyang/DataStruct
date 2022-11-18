#include "iostream"
using namespace std;
struct Node
{
    Node(int x, struct Node *next) : data(x), next(next) {}
    int data;
    struct Node *next;
};
void Create(Node *&L, int a[], int n)
{
    L = new Node(-1, NULL);
    Node *r = L;
    for (int i = 0; i < n; i++)
    {
        Node *t = new Node(a[i], NULL);
        r->next = t;
        r = t;
    }
}
void Print(Node *L)
{
    Node *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    Node *L;
    Create(L, a, 6);
    Print(L);
}