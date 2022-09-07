//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void DFS(LGraph G,int u)
{
    visit[u]=true;
    //通过连接表访问邻接节点
    for (ArcNode *p=G.vexlist[u].firstarc;p;p=p->next) {
        int v=p->adjvex;
        if(!visit[v])
            DFS(G,v);
    }
}

int DFS_Travesal(LGraph G)
{
    memset(vis,false, sizeof(visit));
    int num=0;
    for(int i=1;i<=G.vexnum;i++)
    {
        if(!visit[i])//没访问的节点调用DFS
        {
            DFS(G,i);
            num++;//连通分量个数
        }
    }
    return num;
}

int main() {
    cout << "AC！" << endl;
    return 0;
}