//
// Created by koyan on 2022/8/29.
//
#include "iostream"
#include "BST.h"
using namespace std;

bool Detele(BiTree &p,BiTree &fa,int lr)
{
    BiNode *q,*s;
    if(p->lson==NULL)//如果左子树为空，直接用右子树替换它
    {
        q=p;
        if(lr==0) fa->lson=p->rson;
        else fa->rson=p->rson;
        free(q);
    }
    else if(p->rson==NULL)
    {
        q=p;
        if(lr==0) fa->lson=p->lson;
        else fa->rson=p->lson;
        p=p->lson;
        free(q);
    }
    else{
        q=p;
        s=p->lson;
        while(s->rson){q=s,s=s->rson;}//找到p节点前驱
        p->data=s->data;
        if(q!=p) q->rson=s->lson;
        else q->lson=s->lson;
        free(s);
    }
}

bool delete_node(BiTree T,BiTree fa,int key,int lr)
{
    //T是当前访问节点，fa是T的双亲结点，key是要删除节点的值，lr=0代表左子树，lr=1代表右子树
    if(T==NULL) return false;
    if(T->data>key) return delete_node(T->lson,T,key,0);
    else if(T->data<key) return delete_node(T->rson,T,key,1);
    else return Detele(T,fa,lr);
}

int main()
{
    BiTree T;
    int str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Create_BST(T,str,7);
    InOrder(T);
    delete_node(T,NULL,66,1);
    puts("");
    InOrder(T);
    return 0;
}