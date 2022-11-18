#include "iostream"
using namespace std;
struct Node
{
    Node(int d, struct Node *l, int ltag, struct Node *r, int rtag) : data(d), lson(l), rson(r), ltag(ltag), rtag(rtag) {} //构造函数
    int data;
    struct Node *lson, *rson;
    int ltag, rtag;
};

int insertnode(Node *&T, int x)
{
    if (!T)
    {
        T = new Node(x, NULL, 0, NULL, 0);
        return 1;
    }
    if (T->data == x)
        return -1;
    if (T->data > x)
        return insertnode(T->lson, x);
    else
        return insertnode(T->rson, x);
}

void create(Node *&T, int a[], int n)
{
    T = NULL;
    for (int i = 0; i < n; i++)
        insertnode(T, a[i]);
}
void visit(Node *&T, Node *&pre)
{
    if (!T->lson)
    {
        T->lson = pre;
        T->ltag = 1;
    }
    if (pre && !pre->rson)
    {
        pre->rson = T;
        pre->rtag = 1;
    }
    pre = T;
}
void PreThread(Node *&T, Node *&pre)
{
    if (T)
    {
        visit(T, pre);
        if (pre->ltag == 0)
            PreThread(T->lson, pre); //防止爱的魔力转圈圈
        PreThread(T->rson, pre);
    }
}
void create_PreThread(Node *&T)
{
    Node *pre = NULL;
    if (T != NULL)
    {
        PreThread(T, pre);
        if (pre->rson == NULL)
            pre->rtag = 1; //处理最后一个节点
    }
}

void inorder(Node *T)
{
    if (T)
    {
        inorder(T->lson);
        cout << T->data << " ";
        inorder(T->rson);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Node *T;
    create(T, a, 5);
    create_PreThread(T);
    inorder(T);
}