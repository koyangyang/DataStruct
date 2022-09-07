//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList LinklistFind(LinkList L,int key)
{
    if(L->next->data==key)
        return L->next;
    LinkList p=L->next->next,pre=L->next;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            int tmp=p->data;
            p->data=pre->data;
            pre->data=tmp;
            return pre;
        }
        pre=p;
        p=p->next;
    }
    return NULL;
}

int findpos(int a[],int n,int key)
{
    if(a[0]==key) return 0;//第一个元素无前驱
    for (int i = 0; i < n; ++i) {
        if(a[i]==key) swap(a[i],a[i-1]);//交换前驱节点
        return i-1;
    }
    return -1;//没找到返回-1
}

int main() {
    cout << "AC！" << endl;
    return 0;
}