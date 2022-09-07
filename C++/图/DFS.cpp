#include <bits/stdc++.h>
#include "LGraph.h"
using namespace std;
const int n=5;

bool* vis=(bool*)malloc((n+1)* sizeof(bool));

void DFS(LGraph G,int u)
{
    vis[u]=true;
    cout<<u<<" ";
    for(ArcNode *p=G.vexlist[u].firstarc;p;p=p->next)
    {
        int v=p->adjvex;
        if(!vis[v])
            DFS(G,v);
    }
}

int DFS_Travel(LGraph G)
{
	int sum=0;
    memset(vis,false, sizeof(vis));//初始化标记数组
    for (int i = 1; i <=G.vexnum ; ++i)
        if(!vis[i])
        {
			DFS(G,i);
			puts("");
			sum++;
		}
    return sum;        
}

int main() {
    LGraph G;
    InitLGraph(G,n);
    cout<<DFS_Travel(G);
    return 0;
}
