//
// Created by koyan on 2022/8/29.
//
#ifndef C_BST_H
#define C_BST_H
#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    struct BiNode *lson,*rson;
}BiNode,*BiTree;

int Insert_BST(BiTree &T,int x)
{
    if(T==NULL)
    {
        T=new BiNode;
        T->data=x;
        T->lson=T->rson=NULL;
        return 1;
    }
    else{
        if(T->data==x) return 0;
        else if(T->data>x) return Insert_BST(T->lson,x);
        else return Insert_BST(T->rson,x);
    }
}

void Create_BST(BiTree &T,int a[],int n)
{
    T=NULL;
    for (int i = 0; i < n; ++i)
        Insert_BST(T,a[i]);
}

void visit(BiTree T)
{
    cout<<T->data<<" ";
}

void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lson);
        visit(T);
        InOrder(T->rson);
    }
}

#endif //C_BST_H
