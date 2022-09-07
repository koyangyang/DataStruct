//#include <bits/stdc++.h>
#include <iostream>
#include "BiTree.h"
using namespace std;

int main() {
    BiTree T;   //树根
    int str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Create_BST(T,str,7);
    InOrder(T);
    return 0;
}