#include "iostream"
#include "vector"
using namespace std;

const int N = 10001;
typedef struct ArcNode
{
    int adjvex;
    int value;
    ArcNode *next;
} ArcNode;

typedef struct
{
    int data;
    ArcNode *firstArc;
} VNode;

typedef struct
{
    VNode vetexList[N];
    int arcnum, vexnum;
} LGraph;

// 创建邻接表
void create(LGraph &G, int n, int m)
{
    G.arcnum = m; //节点数量
    G.vexnum = n; //边的个数

    for (int i = 1; i <= n; i += 1)
    { //初始化
        G.vetexList[i].data = i;
        G.vetexList[i].firstArc = NULL;
    }

    for (int i = 0; i < m; i += 1)
    {
        int s, e, v;
        cin >> s >> e >> v;
        ArcNode *p = new ArcNode;
        p->adjvex = e;
        p->value = v;
        p->next = G.vetexList[s].firstArc;
        G.vetexList[s].firstArc = p;
    }
}

int dis[N];
bool vis[N];
vector<int> stk;
void Prime(LGraph G, int s)
{
    for (int i = 0; i <= G.vexnum; i++)
    {
        dis[i] = 99999;
        vis[i] = 0;
    }
    stk.push_back(s);
    vis[s] = true;
    for (ArcNode *p = G.vetexList[s].firstArc; p; p = p->next)
    {
        int v = p->adjvex;
        dis[v] = p->value;
    }
    for (int i = 0; i < G.vexnum - 1; i++)
    {
        int min = 0;
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (dis[min] >= dis[j] && !vis[j])
                min = j;
        }
        stk.push_back(min);
        vis[min] = true;
        for (ArcNode *p = G.vetexList[min].firstArc; p; p = p->next)
        {
            int v = p->adjvex;
            if (dis[v] > dis[min] + p->value && !vis[v])
                dis[v] = dis[min] + p->value;
        }
    }
    for (int i = 0; i < stk.size(); i++)
        cout << stk[i] << " ";
}
/*
5 10
1 2 1
2 1 1
1 3 2
3 1 2
2 4 4
4 2 4
3 4 2
4 3 2
4 5 5
5 4 5
*/

int main()
{
    int n, m;
    cin >> n >> m;
    LGraph G;
    create(G, n, m);
    Prime(G, 1);
    return 0;
}