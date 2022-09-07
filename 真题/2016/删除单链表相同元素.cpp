//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void Delete(LinkList &L)
{
    LinkList p=L->next;
    while(p!=NULL)
    {
        LinkList pre=p,q=p->next,tmp;
        while(q!=NULL)
        {
            if(q->data==p->data)
            {
                tmp=q;
                pre->next=q->next;
                free(tmp);
                q=q->next;
            }
            else{
                q=q->next;
                pre=pre->next;
            }
        }
    }
}

int main() {
    cout << "AC！" << endl;
    return 0;
}