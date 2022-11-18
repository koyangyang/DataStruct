#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
bool judge(Node *T)
{
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        Node *t=q.front();q.pop();
        if(t)
        {
            q.push(t->lson);//空结点也压尽栈中
            q.push(t->rson);//空结点也压尽栈中
        }else//如果是空结点
        {
            while(!q.empty())//在栈中看剩余同层结点有没有非空的
            {
                Node *p=q.front();q.pop();
                if(p) return false;
            }
        }
    }
    return true;
}
int main() {
    Node *T;
    CreateBST(T,feiwanquan,num);
    InOrder(T);
    puts("");
    cout<<judge(T);
    return 0;
}