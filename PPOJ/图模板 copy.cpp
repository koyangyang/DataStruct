#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

typedef struct ArcNode {
	int adjvex;
	ArcNode *next;
} ArcNode;

typedef struct {
	int data;
	ArcNode *firstArc;
} VNode;

typedef struct {
	VNode vexlist[N];
	int arcnum, vexnum;
} LGraph;

// 创建邻接表
void create(LGraph &G, int n, int m) {
	G.arcnum = m;//节点数量
	G.vexnum = n;//边的个数
	
	for (int i = 1; i <= n; i += 1) {//初始化
		G.vexlist[i].data = i;
		G.vexlist[i].firstArc = NULL;
	}
	
	for (int i = 0; i < m; i += 1) {
		int s, e;
		cin >> s >> e;
		ArcNode *p = new ArcNode;
		p->adjvex = e;
		p->next = G.vexlist[s].firstArc;
		G.vexlist[s].firstArc = p;
	}
}
bool vis[N];
vector<int> stk;
int top=0;
void DFS(LGraph G,int a)
{
	stk.push_back(a);
	top++;
	if(vis[a])
	{
		for(int i=0;i<top;i++){
			cout<<stk[i];
		}
		return;
	}
	vis[a]=true;
	for(ArcNode* p=G.vexlist[a].firstArc;p;p=p->next)
	{
		int v=p->adjvex;
		if(!vis[v])
		{
			DFS(G,v);
			stk.pop_back();
			top--;
			vis[v]=false;
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		LGraph G;
		create(G, n, m);
		DFS(G,2);
	}
	return 0;
}
