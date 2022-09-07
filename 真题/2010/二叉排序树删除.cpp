//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//bool Detele(BSTree &p,BSTree &fa,int lr)
//{
//    BSTNode *q,*s;
//    if(p->lchild==NULL)//如果左子树为空，直接用右子树替换它
//    {
//        q=p;
//        if(lr==0) fa->lchild=p->rchild;
//        else fa->rchild=p->rchild;
//        free(q);
//    }
//    else if(p->rchild==NULL)
//    {
//        q=p;
//        if(lr==0) fa->lchild=p->lchild;
//        else fa->rchild=p->lchild;
//        p=p->lchild;
//        free(q);
//    }
//    else{
//        q=p;
//        s=p->lchild;
//        while(s->rchild){q=s,s=s->rchild;}//找到p节点前驱
//        p->data=s->data;
//        if(q!=p) q->rchild=s->lchild;
//        else q->lchild=s->lchild;
//        free(s);
//    }
//}
//
//bool delete_node(BSTree T,BSTree fa,int key,int lr)
//{
//    //T是当前访问节点，fa是T的双亲结点，key是要删除节点的值，lr=0代表左子树，lr=1代表右子树
//    if(T==NULL) return false;
//    if(T->data>key) return delete_node(T->lchild,T,key,0);
//    else if(T->data<key) return delete_node(T->rchild,T,key,1);
//    else return Detele(T,fa,lr);
//}

int main() {
    cout << "AC！" << endl;
    return 0;
}