//
// Created by koyan on 2022/8/30.
//
#include "iostream"
#include "queue"
#include "MGraph.h"
using namespace std;

const int n=10;
bool vis[n+1][n+1];
//八个方向
const int dic[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//四个方向
//const int dic[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void BFS(MGraph G, int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=true;
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        for(int j=0;j<8;j++)//依次搜索八个方向
        {
            int x=temp.first+dic[j][0];
            int y=temp.second+dic[j][1];
            //防止x和y不能越过边界、用‘@’表示油田
            if(!vis[x][y]&&x>=1&&x<=n&&y>=1&&y<=n&&G.arcs[x][y]=='@')
            {
                q.push({x,y});
                vis[x][y]=1;
            }
        }
    }
}

int BFS_Travel(MGraph G)
{
    int sum=0;//记录连通分量
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if(!vis[i][j])
            {
                BFS(G,i,j);
                sum++;
            }
        }
}
