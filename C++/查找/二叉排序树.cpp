//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
//54,20,66,40,28,79,58

//插入操作，递归实现
int BST_Insert(BiTree &T,KeyType k)
{
    if(T==NULL)
    {
        T=(BiTree)malloc(sizeof(BSTNode));  //为新节点申请空间
        T->key=k;   //
        T->lchild=T->rchild=NULL;   //左孩子右孩子为空
        return 1;//代表插入成功
    }
    else if(k==T->key)
        return 0;//发现相同元素，就不插入
    else if(k<T->key)    //如果要插入的结点，小于当前结点
        return BST_Insert(T->lchild,k);   //放入左孩子中，递归实现
    else
        return BST_Insert(T->rchild,k);   //放入右孩子中，递归实现
}
//创建二叉排序树
void Creat_BST(BiTree &T,KeyType str[],int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert(T,str[i]);  //把某一个结点放入二叉查找树中
        i++;
    }
}


void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        cout<< "  "<<T->key;
        InOrder(T->rchild);
    }
}

//二叉排序树的创建，中序遍历，查找，删除
int main()
{
    BiTree T;   //树根
    KeyType str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Creat_BST(T,str,7);
    InOrder(T);
    return 0;
}