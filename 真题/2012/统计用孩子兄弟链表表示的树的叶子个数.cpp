//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int CountLeaves(BiTree BT)
{
    if(BT==NULL) return 0;
    if(BT->lchild==NULL)//如果节点左子树为空，说明这个节点本身就是叶子节点
        return CountLeaves(BT->rchild)+1;
    else return CountLeaves(BT->lchild)+CountLeaves(BT->rchild);
}

int main() {
    cout << "AC！" << endl;
    return 0;
}