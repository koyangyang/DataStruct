#ifndef DS_BST_H
#define DS_BST_H
#include <iostream>
using namespace std;
typedef struct Node
{
    Node(int w, struct Node *l, struct Node *r):data(w),lson(l),rson(r){}
    int data;
    struct Node *lson,*rson;
};
int insert(Node *&T,int x)
{
    if(!T)
    {
        T=new Node(x,NULL,NULL);
        return 1;
    }
    if(T->data==x) return -1;
    else if(T->data>x) return insert(T->lson,x);
    else return insert(T->rson,x);
}
void CreateBST(Node *&T,int a[],int n)
{
    T=NULL;
    for (int i = 0; i <n ; ++i) {
        insert(T,a[i]);
    }
}
int example[]={50,25,60,11,40};
int feiwanquan[]={50,25,60,11,55};
int num=5;
void InOrder(Node *T)
{
    if(T)
    {
        InOrder(T->lson);
        cout<<T->data<<" ";
        InOrder(T->rson);
    }
}
#endif //DS_BST_H
