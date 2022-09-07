//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void DFS(LGraph G,int u)
{
    visit[u]=true;
    //通过邻接表访问邻接点
    for(ArcNode *p=G.vexlist[u].firsarc;p;p=p->next)
    {
        int v=p->adjvex;
        if(!visit[v])
            DFS(G,v);
    }
}

int DFS_tracal(LGraph G1)
{
    memset(visit,false, sizeof(visit));
    int num=0;
    for (int i = 1; i <= G1.vexnum; ++i)
    {
        if(!visi[i])
        {
            DFS(LGraph,i);
            num++;
        }
    }
    return num;
}

int main() {
    cout << "AC！" << endl;
    return 0;
}