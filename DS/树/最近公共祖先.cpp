#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
int flag=true;
bool judge(Node *T,int x,int y)
{
    if(!T||!flag)
        return false;
    bool l=judge(T->lson,x,y);
    bool r=judge(T->rson,x,y);
    if((T->data==x||T->data==y)&&flag)
    {
        if(l||r)
        {
            flag=false;
            cout<<T->data;
        }
            else return true;
    }
    if(l&&r&&flag)
    {
        cout<<T->data;
        flag=false;
    }
    return l||r;
}
int main() {
    Node *T;
    CreateBST(T,example,num);
    judge(T,11,60);
    return 0;
}