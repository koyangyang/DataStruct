//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef int KeyType;
typedef struct BitNode{
    KeyType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;
//54,20,66,40,28,79,58

//二叉排序树插入节点
int insert_BST(BiTree &BST,KeyType key)
{
    if (BST==NULL)//插入新的节点
    {
        BST=(BiTree)malloc(sizeof(BitNode));//申请内存空间
        BST->data=key;
        BST->lchild=BST->rchild=NULL;
        return 1;//插入成功返回1
    }
    if(BST->data==key) return 0;//已经存在则不插入，返回0
    else if(BST->data>key) return insert_BST(BST->lchild,key);//如果根节点值大于插入值，则在左区间插入
    else return insert_BST(BST->rchild,key);//否则在右区间插画如
}

//创建二叉排序树
void create_BST(BiTree &BST,int a[],int n)
{
    BST=NULL;//初始化
    for (int i = 0; i < n; ++i)
        insert_BST(BST,a[i]);//依次插入节点
}

void visit(BitNode *T)
{
    cout<<T->data<<" ";
}

//中序遍历
void InOrder(BiTree BST)
{
    if(BST!=NULL)
    {
        InOrder(BST->lchild);
        visit(BST);
        InOrder(BST->rchild);
    }
}

//后序遍历
void PostOrder(BiTree BST)
{
    if(BST!=NULL)
    {
        PostOrder(BST->lchild);
        PostOrder(BST->rchild);
        visit(BST);
    }
}

//先序遍历
void PreOrder(BiTree BST)
{
    if(BST!=NULL)
    {
        visit(BST);
        PreOrder(BST->lchild);
        PreOrder(BST->rchild);
    }
}

int main()
{
    BiTree T;   //树根
    KeyType str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    create_BST(T,str,7);
    puts("中序遍历");
    InOrder(T);
    puts("");
    puts("后序遍历");
    PostOrder(T);
    puts("");
    puts("先序遍历");
    PreOrder(T);
    return 0;
}