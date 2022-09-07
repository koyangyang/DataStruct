//
// Created by koyan on 2022/8/28.
//

#ifndef C_MGRAPH_H
#define C_MGRAPH_H
#include "iostream"
using namespace std;
#define MaxSize 100
typedef struct
{
    int arcs[MaxSize][MaxSize];//定义邻接矩阵
    int vexnum,arcnum;//顶点集和边集
}MGraph;
bool vis[MaxSize];
/*
4
0 0 0 1
0 0 1 1
0 1 0 1
1 1 1 0
*/

void InitMGraph(MGraph &G,int n)
{
	for(int j=0;j<=n;j++)
		vis[j]=false;
    G.vexnum=n;G.arcnum=0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <=n ; ++j) {
            cin>>G.arcs[i][j];
            G.arcnum++;
        }
}

#endif //C_MGRAPH_H
