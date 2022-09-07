//
// Created by koyan on 2022/8/23.
//

#ifndef C_BITREE_H
#define C_BITREE_H

#include "iostream"
using namespace std;
typedef struct BNode{
    BNode *lson,*rson;
    int data;
}BNode,*BiTree;

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

int Insert_BST(BiTree &T,int key)
{
    if(T==NULL)
    {
        T=new BNode;
        T->data=key;
        T->rson=T->lson=NULL;
        return 1;
    }
    if(T->data==key) return 0;
    if(T->data>key) return Insert_BST(T->lson,key);
    else return Insert_BST(T->rson,key);
}

void Create_BST(BiTree &T,int a[],int n)
{
    T=NULL;
    for (int i = 0; i < n; ++i)
        Insert_BST(T,a[i]);
}

void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->lson);
        PostOrder(T->rson);
        visit(T);
    }
}

void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        visit(T);
        PreOrder(T->lson);
        PreOrder(T->rson);
    }
}

#endif //C_BITREE_H
