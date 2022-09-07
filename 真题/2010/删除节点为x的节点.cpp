//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void my_delete(node *root,node *pre,int x,int flag)
{
    if(root==NULL)
        return ;
    my_delete(root->left,root,x,1);
    my_delete(root->right,root,x,2);
    if(root->data==x&&root->left==NULL&&root->right==NULL)
    {
        if(flag==1)
            pre->left=NULL;
        else
            pre->right=NULL;
    }
}

int main() {
    cout << "AC！" << endl;
    return 0;
}