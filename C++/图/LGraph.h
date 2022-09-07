#ifndef C_LGraph_H
#define C_LGraph_H

#include "iostream"
#include "MGraph.h"
using namespace std;
#define MaxSize 100
typedef struct ArcNode
{
	int adjvex;
	ArcNode* next;
}ArcNode;

typedef struct VNode
{
	int adjvex;
	ArcNode* firstarc;
}VNode,Adjlist[MaxSize];

typedef struct LGraph
{
	Adjlist vexlist;
	int vexnum,arcnum;
}LGraph;

void InitLGraph(LGraph &G,int n)
{
	G.vexnum=n;G.arcnum=0;
	for (int i = 1; i <= G.vexnum; ++i) {
		G.vexlist[i].firstarc=NULL;
	}
}

void Matrix_to_Vector(MGraph G,LGraph &G1)
{
	cout<<G.vexnum<<G.arcnum;
	G1.arcnum=G.arcnum,G1.vexnum=G1.vexnum;
	for (int i = 1; i <= G1.vexnum ; ++i)
		G1.vexlist[i].firstarc=NULL;
	for (int i = 1; i <=G1.vexnum ; ++i)
		for (int j = 1; j <=G1.vexnum ; ++j) {
			if(G.arcs[i][j]==1)
			{
				//采用头插法
				ArcNode *p=new ArcNode;
				p->adjvex = j;
				if(G1.vexlist[i].firstarc==NULL) p->next=NULL;
				else p->next=G1.vexlist[i].firstarc;
				G1.vexlist[i].firstarc=p;
			}
		}
}

void Print(LGraph G)
{
	for (int i = 1; i <= G.vexnum; ++i) {
		ArcNode *p=G.vexlist[i].firstarc;
		while(p!=NULL)
		{
			cout<<p->adjvex<<" ";
		}
		puts("");
	}
}
#endif //C_LGraph_H
