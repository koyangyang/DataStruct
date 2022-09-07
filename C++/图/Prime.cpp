#include "iostream"
using namespace std;
const int N=10010;
int n,matrix[N][N];//邻接矩阵
int dis[N],Mincost;
bool vis[N];

void prime()
{
    vis[1]=1;//默认从1开始
    for (int i = 1; i <=n ; ++i)
        dis[i]=matrix[1][i];//存入1号节点到其他节点的距离
    for (int i = 0; i < n-1; ++i) {//进行n-1次循环，每次将一个节点加入
        int Min=INF,Minid;
        for (int j = 1; j <= n ; ++j) {//遍历选出成本最低且未加入的节点
            if(vis[j]) continue;//如果已经加入则跳过
            if(Min>dis[j])//将j列为候选点
            {
                Minid=j;
                Min = dis[j];
            }//if
        }//for
        Mincost +=dis[Minid];//更新答案
        vis[Minid]= 1;
        for (int j = 1; j <=n ; ++j) {//利用新加入的点更新dis数组
            if(vis[j])continue;
            if(dis[j]>matrix[Minid][j])
            {
                dis[j]=matrix[Minid][j];
            }
        }//for
    }//for
}