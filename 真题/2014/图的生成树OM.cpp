//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int FindRoot(int r)//并查集
{
    if(F[r]==r) return r;
    else return F[r]=FindRoot(F[r]);
}

void spanTree(Graph G,Graph &T)
{
    T.vertex=G.vertex;//T的顶点集即为G的顶点集
    int m=G.arcnum;//首先初始化不连通分量数为1
    int edgenum=0;
    for(int i=1;i<=m;i++)
    {
        //选择第i条边，并获得断点{u,v}
        int u=G.edge[i].u,v=G.edge[i].v;
        //通过并查集找到u，v所属的连通分量
        int rootu=FindRoot(u);
        int rootv=FindRoot(v);
        if(rootu!=rootv)//两者不属于同一个连通分量
        {
            T.edge[++edgenum]={u,v};//将该边放入T中
            F[rootu]=F[rootv];//将u，v所属连通分量连接成一个
        }
    }
}

int main() {
    cout << "AC！" << endl;
    return 0;
}