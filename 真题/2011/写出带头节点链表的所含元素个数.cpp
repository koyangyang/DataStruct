//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int CountNodes(LinkList L)
{
    LNode *p=L->next;
    int count=0;
    while(p!=NULL)//依次遍历链表
    {
        count++;
        p=p->next;
    }
    return count;
}

int main() {
    cout << "AC！" << endl;
    return 0;
}