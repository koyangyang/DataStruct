//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

LinkList merge(LinkList &L1,int m,LinkList &L2,int n)
{
    if(m>n)//若L1比L2长
    {
        LinkList p=L2;
        while(p->next!=NULL)
            p=p->next;
        p->next=L1->next;//直接将L1接在L2后面
        return L2;
    }
    else
    {
        LinkList p=L1;
        while(p->next!=NULL)
            p=p->next;
        p->next=L2->next;//直接将L2接在L1后面
        return L1;
    }
}

int main() {
    cout << "AC！" << endl;
    return 0;
}