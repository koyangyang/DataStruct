//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void DFS(LGraph G,int u)
{
    visit[u]=true;
    //采用邻接表
    for(ArcNode *p=G.vexlist[u].firstarc;p;p=p->next)
    {
        int v=p->adjvex;
        if(!visit[v])
            DFS(G,v);
    }
}
int DFS_trace(LGraph G)
{
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=G.vexnum;i++)
    {
        if(!visit[i])
        {
            DFS(G,i);
            sum++;
        }
    }
    return sum;
}


int main() {
    cout << "AC！" << endl;
    return 0;
}