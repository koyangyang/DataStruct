#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *lson,*sibiling;
};
bool* vis=new bool[100];
Node* DFSTree(LGraph G,int u)
{
    Node *root=new Node(u,NULL,NULL),*t=root;
    vis[u]=true;
    bool first=true;
    for (ArcNode *p=G.vexlist[u].firstarc;p;p=p->next) {
        int v=p->adjvex;
        if(!vis[v])
        {
            if(first)
            {
                t->lson=DFSTree(G,v);
                first=false;
            } else{
                t->sibiling=DFSTree(G,v);
                t=t->sibiling;
            }
        }
    }
    return root;
}
Node* DFSForest(LGraph G,int u)
{
    memset(vis,false, sizeof(vis));
    Node *root;
    vis[u]=true;
    for (int i = 1; i <=G.vexnum ; ++i) {
        if(!vis[i])
        {
            if(root) root=DFSTree(G,i);
            else
            {
                root->sibiling=DFSTree(G,i);
                root=root->sibiling;
            }
        }
    }
}
int main() {

    return 0;
}