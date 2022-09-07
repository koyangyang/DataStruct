//#include <bits/stdc++.h>
#include <iostream>
#include "stack"
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
    stack<BiTree> s;
    BiTree p=T;
    while(p||!s.empty())
    {
        if(p){
            s.push(p);
            p=p->lson;
        }
        else{
            p=s.top();s.pop();
            visit(p);
            p=p->rson;
        }
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
    InOrder(T);
    return 0;
}