#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
typedef struct ArcNode
{
  int adjvex;
  struct ArcNode *next;
} ArcNode;
typedef struct VNode
{
  int data;
  ArcNode *firstarc;
} VNode, Adjlist[N];
typedef struct LGraph
{
  int arcnum, vexnum;
  Adjlist vexlist;
} LGraph;

// 创建邻接表
void create(LGraph &G, int n, int m)
{
  G.arcnum = m; //节点数量
  G.vexnum = n; //边的个数

  for (int i = 1; i <= n; i += 1)
  { //初始化
    G.vexlist[i].data = i;
    G.vexlist[i].firstarc = NULL;
  }

  for (int i = 0; i < m; i += 1)
  {
    int s, e;
    cin >> s >> e;
    ArcNode *p = new ArcNode;
    p->adjvex = e;
    p->next = G.vexlist[s].firstarc;
    G.vexlist[s].firstarc = p;
  }
}
/*
6 11
2 1
2 4
3 2
3 6
4 3
4 5
4 6
5 1
6 1
6 2
6 5
*/
int *vis = new int[N];
void BFS(LGraph G, int u)
{
  queue<int> q;
  cout << u << " ";
  q.push(u);
  vis[u] = 1;
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for (ArcNode *p = G.vexlist[u].firstarc; p; p = p->next)
    {
      int v = p->adjvex;
      if (vis[v] == 0)
      {
        q.push(v);
        cout << v << " ";
        vis[v] = 1;
      }
    }
  }
}
void BFS_Travel(LGraph G)
{
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= G.vexnum; i++)
  {
    if (vis[i] == 0)
    {
      BFS(G, i);
    }
  }
}

int main()
{
  int n, m;
  while (cin >> n >> m)
  {
    LGraph G;
    create(G, n, m);
    BFS_Travel(G);
  }
  return 0;
}