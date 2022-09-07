//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int KeyType;
typedef struct BitNode{
    KeyType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

int insert_BST(BiTree &BST,int key)
{
    if(BST==NULL)
    {
        BST=(BiTree)malloc(sizeof(BitNode));
        BST->data=key;
        BST->lchild=BST->rchild=NULL;
        return 1;
    }
    else if(BST->data==key) return 0;
    else if(BST->data>key) return insert_BST(BST->lchild,key);
    return insert_BST(BST->rchild,key);
}

void create_BST(BiTree &BST,int a[],int n)
{
    BST=NULL;
    for (int i = 0; i < n; ++i)
        insert_BST(BST,a[i]);
}

int CountLeaves(BiTree BST)
{
    if (BST==NULL) return 0;
    if(BST->lchild==NULL&&BST->rchild==NULL) return 1;
    return CountLeaves(BST->lchild)+CountLeaves(BST->rchild);
}

int main() {
    BiTree T;   //树根
    KeyType str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    create_BST(T,str,7);
    cout<<CountLeaves(T);
    return 0;
}