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

void InitMGraph(MGraph &G,int n)
{
    G.vexnum=n;G.arcnum=0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <=n ; ++j) {
            G.arcs[i][j]=1;
            G.arcnum++;
        }
}

#endif //C_MGRAPH_H
