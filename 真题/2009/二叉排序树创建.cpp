//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct BitNode{
    int data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;


int Insert_BST(BiTree &BT,int key)
{
    if(BT==NULL)
    {
        BT=(BiTree)malloc(sizeof(BitNode));
        BT->lchild=BT->rchild=NULL;
        BT->data=key;
        return 1;
    }
    else if(BT->data==key) return 0;
    else if(BT->data>key) return Insert_BST(BT->lchild,key);
    else return Insert_BST(BT->rchild,key);
}

void Create_BST(BiTree &BT,int a[],int n)
{
    BT=NULL;
    for(int i=0;i<n;i++)
        Insert_BST(BT,a[i]);
}

void InOrder(BiTree &BT)
{
    if(BT!=NULL)
    {
        InOrder(BT->lchild);
        cout<<BT->data<<" ";
        InOrder(BT->rchild);
    }
}



signed main() {
    BiTree T;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    Create_BST(T,a,10);
    InOrder(T);
    return 0;
}