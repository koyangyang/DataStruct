#include "iostream"
#include "vector"
using namespace std;
#define Max 100

typedef struct edge
{
	int x;
	int y;
	int v;
}edge;
typedef struct MGraph
{
	edge edges[Max];
	int vexnum,arcnum;//顶点集和边集
}MGraph;

int parent[Max];
vector<edge*> Edges;


int findroot(int x)
{
	while(x!=parent[x])
		x=parent[x];
	return x;
}

void initparent(int n)
{
	for(int i=1;i<=n;i++)
		parent[i]=i;
}

void Union(int a,int b)
{
	int ra=findroot(a);
	int rb=findroot(b);
	if(ra!=rb)
	{
		parent[b]=ra;
	}
}

bool check(int a,int b)
{
	if(findroot(a)==findroot(b)) return true;
	else return false;
}

int Kruskal(MGraph G,MGraph &G1)
{
	G1.vexnum=G.vexnum;
	int t=0;
	G1.arcnum=0;
	Quick_Sort(G.edges,0,G.arcnum);
	for(int i=0;i<G.arcnum;i++){
		int a=G.edges[i].x;
		int b=G.edges[i].y;
		if(!check(a,b))
		{
			Union(a,b);
			G1.edges[t].x=a;
			G1.edges[t].y=b;
			G1.edges[t].v=G.edges[i].v;
			t++;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	MGraph G;
	InitMGraph(G, n);
	return 1;
}
