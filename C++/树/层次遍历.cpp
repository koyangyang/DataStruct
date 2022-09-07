//#include <bits/stdc++.h>
#include <iostream>
#include "queue"
using namespace std;
typedef struct BNode{
    BNode *lson,*rson;
    int data;
}BNode,*BiTree;

void visit(BiTree T)
{
    cout<<T->data<<" ";
}

void LevelOrder(BiTree T)
{
    if(T==NULL) return;//空树直接返回
    queue<BiTree> q;
    BiTree p=T;
    q.push(p);//将根节点压入栈中
    while(!q.empty())//队列非空
    {
        BiTree t=q.front();//取出队首元素
        q.pop();//弹出队首,C++语法
        visit(t);//访问队首元素
        if(t->lson!=NULL) //左子树非空则入队
            q.push(t->lson);
        if(t->rson!=NULL) //右子树非空则入队
            q.push(t->rson);
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

int main() {
    BiTree T;   //树根
    int str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Create_BST(T,str,7);
    LevelOrder(T);
    return 0;
}