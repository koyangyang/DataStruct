#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
};
typedef struct Edge
{
    int adjvex;
    ArcNode *firstarc;
}Edge;
typedef struct LGraph
{
    int arcnum,vexnum;
    Edge vexlist[MaxSize];
};
bool TopSort(LGraph G)
{
    int sum=0;queue<int> q;
    int *degree=new int[G.vexnum+1];
    memset(degree,0, sizeof(degree));
    for (int i = 1; i <=G.vexnum; ++i) {
        for(ArcNode *p=G.vexlist[i].firstarc;p;p=p->next)
        {
            int v=p->adjvex;
            degree[v]++;
        }
    }
    for(int i=1;i<=G.vexnum;i++)
        if(degree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int u=q.front();q.pop();
        sum++;
        for(ArcNode *p=G.vexlist[u].firstarc;p;p=p->next)
        {
            int v=p->adjvex;
            if(!(degree[v]--))
                q.push(v);
        }
    }
    return sum==G.vexnum?true: false;
}
int main() {

    return 0;
}