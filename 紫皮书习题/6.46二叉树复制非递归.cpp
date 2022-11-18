#include "iostream"
#include "queue"
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

BiTree Copy(BiTree B)
{
    BiTree p = B, T = (BiTree)malloc(sizeof(BiNode));
    queue<BiTree> q;
    queue<BiTree> tq;
    q.push(p);
    tq.push(T);
    while (!q.empty())
    {
        BiTree tmp = q.front();
        q.pop();
        BiTree tmpq = tq.front();
        tq.pop();
        tmpq->data = tmp->data;
        if (tmp->lson)
        {
            tmpq->lson = (BiTree)malloc(sizeof(BiNode));
            q.push(tmp->lson);
            tq.push(tmpq->rson);
        }
        if (tmp->rson)
        {
            tmpq->rson = (BiTree)malloc(sizeof(BiNode));
            q.push(tmp->rson);
            tq.push(tmpq->rson);
        }
    }
    return T;
}

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lson);
        cout << T->data << " ";
        InOrder(T->rson);
    }
}

int main()
{
    BiTree B;
    Create_BST(B, example, 6);
    BiTree T = Copy(B);
    InOrder(T);
    return 0;
}