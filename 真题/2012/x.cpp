//#include <bits/stdc++.h>
#include <iostream>
#include "stack"
using namespace std;
typedef struct BNode {
    int data;
    BNode *lson, *rson;
} BNode, *BiTree;
stack<BiTree> s;
void isx(BiTree p,int x)
{
    if(p->data==x)
    {
        while(!s.empty())
        {
            cout<<s.top()->data<<" ";
            s.pop();
        }
        return;
    }
}

void PostOrder(BiTree T,int x)
{
    BiTree p=T,r=NULL;
    while(p||!s.empty())
    {
        if(p)
        {
            isx(p,x);
            s.push(p);
            p=p->lson;
        }
        else{
            p=s.top();
            if(p->rson&&p->rson!=r) {
                p = p->rson;
            } else{
                s.pop();
                isx(p,x);
                r=p;
                p=NULL;
            }
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
    PostOrder(T,58);
    return 0;
}