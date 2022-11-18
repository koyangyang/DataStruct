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

int PreOrderK(BiTree T, int k)
{
    if (T)
    {
        if (k == 0)
            return T->data;
        else
        {
            k--;
            int l = PreOrderK(T->lson, k);
            if(l) return l;
            else return PreOrderK(T->rson, k);
        } 
    }
    return 0;
}

int main()
{
    BiTree B;
    Create_BST(B, example, 7);
    cout << PreOrderK(B, 3);
    return 0;
}
