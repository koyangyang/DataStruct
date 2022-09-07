//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

int insert_BST(ThreadTree &BST,int key)
{
    if (BST==NULL)
    {
        BST=(ThreadTree)malloc(sizeof(ThreadNode));
        BST->data=key;
        BST->lchild=BST->rchild=NULL;
        BST->ltag=BST->rtag=0;
        return 1;
    }
    if(BST->data==key) return 0;
    else if(BST->data>key) return insert_BST(BST->lchild,key);
    else return insert_BST(BST->rchild,key);
}

void create_BST(ThreadTree &BST,int a[],int n)
{
    BST=NULL;
    for (int i = 0; i < n; ++i)
        insert_BST(BST,a[i]);
}

void visit(ThreadTree &p,ThreadTree &pre)
{
    if(p->lchild==NULL)
    {
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL)
    {
        pre->rchild=p;
        pre->rtag=1;
    }
    pre=p;
}

void preThread(ThreadTree &p,ThreadTree &pre)
{
    if(p!=NULL)
    {
        visit(p,pre);
        if(p->ltag==0)
            preThread(p->lchild,pre);
        preThread(p->rchild,pre);
    }
}


void create_PreThread(ThreadTree &T)
{
    ThreadTree pre=NULL;
    if(T!=NULL)
    {
        preThread(T,pre);
        if(pre->rchild==NULL)
            pre->rtag=1;//处理最后一个节点
    }
}

ThreadNode *FirstNode(ThreadNode *p)
{
    while (p->ltag==0) p=p->lchild;
    return p;
}

ThreadNode *NextNode(ThreadNode *p)
{
    if(p->rtag==0) return FirstNode(p->rchild);
    else return p->rchild;
}

void inOrder(ThreadTree T)
{
    for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
        cout<<p->ltag<<" "<<p->data<<" "<<p->rtag<<endl;
}

signed main() {
    ThreadTree T;   //树根
    int a[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    create_BST(T,a,7);
    create_PreThread(T);
    inOrder(T);
    return 0;
}