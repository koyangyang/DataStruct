#include "iostream"
#include <queue>
using namespace std;
struct Node
{
    Node(int w, struct Node *l, struct Node *r) : data(w), lson(l), rson(r) {}
    int data;
    struct Node *lson, *rson;
};
int insert(Node *&T, int x)
{
    if (!T)
    {
        T = new Node(x, NULL, NULL);
        return 1;
    }
    if (T->data == x)
        return 0;
    else if (T->data > x)
        return insert(T->lson, x);
    else
        return insert(T->rson, x);
}
void create(Node *&T, int a[], int n)
{
    T = NULL;
    for (int i = 0; i < n; i++)
        insert(T, a[i]);
}
void visit(Node *T)
{
    cout << T->data << " ";
}
void inorder(Node *T)
{
    if (T)
    {
        inorder(T->lson);
        visit(T);
        inorder(T->rson);
    }
}

int judge(Node *T, bool &result)
{
    if (T)
    {
        int left = judge(T->lson, result);
        int right = judge(T->rson, result);
        if (abs(left - right) > 1)
            result = false;
        return left > right ? left + 1 : right + 1;
    }
    return 0;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    Node *T;
    create(T, a, 6);
    inorder(T);
    puts("");
    bool result = true;
    judge(T, result);
    cout << result << endl;
}