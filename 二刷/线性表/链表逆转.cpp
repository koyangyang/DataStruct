#include "iostream"
using namespace std;

typedef struct Node
{
    Node(int d, struct Node *next) : data(d), next(next) {}
    int data;
    struct Node *next;
};
Node *r;
Node *Create(int a[], int n)
{
    Node *L = new Node(0, NULL);
    r = L;
    for (int i = 0; i < n; i++)
    {
        Node *t = new Node(a[i], NULL);
        r->next = t;
        r = t;
    }
    return L;
}

int main()
{
    int a[] = {1, 5, 2, 6, 7};
    Node *L = Create(a, 5);
    while(!L)
    {
        cout << L->data << endl;
        L = L->next;
    }
    return 0;
}