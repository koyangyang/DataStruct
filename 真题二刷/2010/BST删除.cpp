#include "iostream"
using namespace std;

typedef struct BiNode
{
    int data;
    struct BiNode *lson, *rson;
} BiNode, *BiTree;

int example[] = {54, 20, 66, 40, 28, 79, 58};

int Insert_BST(BiTree &T, int x)
{
    if (T == NULL)
    {
        T = new BiNode;
        T->data = x;
        T->lson = T->rson = NULL;
        return 1;
    }
    else
    {
        if (T->data == x)
            return 0;
        else if (T->data > x)
            return Insert_BST(T->lson, x);
        else
            return Insert_BST(T->rson, x);
    }
}

void Create_BST(BiTree &T, int a[], int n)
{
    T = NULL;
    for (int i = 0; i < n; ++i)
        Insert_BST(T, a[i]);
}

void visit(BiTree T)
{
    cout << T->data << " ";
}

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lson);
        visit(T);
        InOrder(T->rson);
    }
}

void DeleteNode(BiTree &T, BiTree &fa, int lr)
{
    BiTree q, s;
    if (T->rson == NULL && T->lson == NULL)
    {
        q = T;
        s = T->lson;
        while (s->rson)
        {
            q = q->lson;
            s = s->rson;
        }
        T->data = s->data;
        if (q != T)
            q->rson = s->lson;
        else
            q->lson = s->lson;
    }
    else if (T->lson == NULL)
    {
        q = T;
        if (lr == 0)
            fa->lson = T->rson;
        else
            fa->rson = T->rson;
        free(q);
    }
    else
    {
        q = T;
        if (lr == 0)
            fa->lson = T->lson;
        else
            fa->rson = T->lson;
        free(q);
    }
}

void Findx(BiTree &T, BiTree &fa, int x, int lr)
{
    if (T)
    {
        Findx(T->lson, T, x, 0);
        if (T->data == x)
            DeleteNode(T, fa, lr);
        Findx(T->rson, T, x, 1);
    }
}

int main()
{
    BiTree T;
    Create_BST(T, example, 7);
    Findx(T, T, 40, 0);
    InOrder(T);
}