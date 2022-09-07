//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MaxSize 50

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} BNode, *BiTree;

//定义一个栈来存储x的祖先节点
typedef struct {
    BiTree t;
    int tag;
} Stack;

Stack s[MaxSize];

//二叉树非递归后序遍历
void PostOrder(BiTree T, int x) {
    BNode *p = T, *q;
    int top = 0;
    while (p || top > 0) {
        while (p && p->data != x)//一直沿左分支向下并且左分支不为x
        {
            s[++top].t = p;
            s[top].tag = 0;
            p = p->lchild;
        }
        if (p && p->data == x)//打印所有祖先节点
        {
            for (int i = 1; i <= top; ++i)
                cout << s[i].t->data<<" ";
            return;
        }
        while (top > 0 && s[top].tag == 1)//栈顶节点左右子树已经全部访问
            top--;
        if (top > 0) {//访问栈顶节点的右子树
            s[top].tag = 1;
            p = s[top].t->rchild;
        }
    }
}

int Insert_BST(BiTree &T,int key)
{
    if(T==NULL)
    {
        T=new BNode;
        T->data=key;
        T->rchild=T->lchild=NULL;
        return 1;
    }
    if(T->data==key) return 0;
    if(T->data>key) return Insert_BST(T->lchild,key);
    else return Insert_BST(T->rchild,key);
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
    PostOrder(T,28);
    return 0;
}