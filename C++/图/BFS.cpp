//#include <bits/stdc++.h>
#include <iostream>
#include "LGraph.h"
#include "MGraph.h"
#include "queue"
using namespace std;
#define N 5


void visit(int n)
{
    cout<<n;
}
bool* vis=(bool*)malloc((N+1)* sizeof(bool));
queue<int> q;

void BFS(LGraph G,int u)
{
    vis[u]=true;
    visit(u);
    q.push(u);
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(ArcNode *p=G.vexlist[i].firstarc;p;p=p->next)
        {
            int v=p->adjvex;
            if(!vis[v])
            {
                vis[v]=true;
                visit(v);
                q.push(v);
            }
        }
    }
}

void BFS_Travel(LGraph G)
{
    for (int i = 1; i < G.vexnum; ++i) {
        if(!vis[i])
        {
            BFS(G,i);
            puts("");
        }
    }
}


int main() {
    LGraph G;
    MGraph G1;
    InitMGraph(G1,N);
    InitLGraph(G,N);
    Matrix_to_Vector(G1,G);
    Print(G);
    //BFS_Travel(G);
    return 0;
}