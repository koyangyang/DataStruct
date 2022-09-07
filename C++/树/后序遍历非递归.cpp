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

void PostOrder(BiTree T)
{
    stack<BiTree> s;//初始化一个栈
    BiTree p=T,r=NULL;//r指针记录最近访问节点
    while(p||!s.empty())
    {
        if(p)//p非空则先访问其左孩子
        {
            s.push(p);
            p=p->lson;
        }
        else{//p为空则表示左孩子已经全部加入栈中
            p=s.top();//取出栈顶元素
            if(p->rson&&p->rson!=r)//若右子树存在且未被访问过
                p=p->rson;//转向右
            else{
                s.pop();//弹出栈顶元素
                visit(p);//访问栈顶元素
                r=p;//记录最近访问节点
                p=NULL;//访问完后重置p指针
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
    PostOrder(T);
    return 0;
}