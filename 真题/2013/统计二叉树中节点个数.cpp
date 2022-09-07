//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int CountNodes(BiTree BT)
{
    if(BT==NULL) return 0;
    return 1+CountNodes(BT->lchild)+CountNodes(BT->lchild);
}

int main() {
    cout << "AC！" << endl;
    return 0;
}