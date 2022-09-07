//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
bool find(LinkList X,LinkList Y,char &c)
{
    LNode *p=X->next,*q;
    while (p)//每一趟在Y中查找一下当前X字符
    {
        q=Y->next;
        while(q)
        {
            if(p->data==q->data) break;
            q=q->next;
        }
        if(!q)
        {
            c=p->data;
            return true;
        }
        p=p->next;
    }
    return false;
}
int main() {
    cout << "AC！" << endl;
    return 0;
}