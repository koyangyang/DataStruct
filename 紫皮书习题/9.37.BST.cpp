//
// Created by koyan on 2022/8/29.
//
#include "iostream"
#include "BST.h"
using namespace std;

void Delete(BiTree& T)

int main()
{
    BiTree T;
    int str[] = {54, 20, 66, 40, 28, 79, 58}; //将要进入二叉排序树的元素值
    Create_BST(T, str, 7);
    InOrder(T);
    delete_node(T, NULL, 66, 1);
    puts("");
    InOrder(T);
    return 0;
}