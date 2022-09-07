//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int CountHigh(BiTree BT)
{
    if(BT==NULL) return 0;//如果为空返回0
    //递归计算左右子树，返回左右子树最大值+1
    return max(CountHigh(BT->lchild),CountHigh(BT->rchild))+1;
}

int main() {
    cout << "AC！" << endl;
    return 0;
}