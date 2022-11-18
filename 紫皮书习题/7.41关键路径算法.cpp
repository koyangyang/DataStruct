#include "bits/stdc++.h"
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

int ve[N];
int vl[N];
void find(LGraph G, vector<int> top)
{
    for (int i = 1; i <= G.vexnum; i++)
    {
        ve[i] = 0;
    }
    for (int i = 0; i < top.size(); i++)
    {
        int k = top[i];
        ArcNode *p = G.vetexList[k].firstArc;
        while (p)
        {
            int v = p->adjvex;
            if (ve[v] < ve[k] + p->value)
                ve[v] = ve[k] + p->value;
            p = p->next;
        }
    }
    for (int i = 1; i <= G.vexnum; i++)
    {
        vl[i] = ve[G.vexnum];
    }
    for (int i = top.size() - 1; i >= 0; i--)
    {
        int k = top[i];
        ArcNode *p = G.vetexList[k].firstArc;
        while (p)
        {
            int v = p->adjvex;
            if (vl[k] > vl[v] - p->value)
                vl[k] = vl[v] - p->value;
            p = p->next;
        }
    }
    for (int i = 1; i <= G.vexnum; i++)
    {
        cout << ve[i] << " ";
    }
    puts("");
    for (int i = 1; i <= G.vexnum; i++)
    {
        cout << vl[i] << " ";
    }
    puts("");
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (ve[i] == vl[i])
            cout << i << " ";
    }
}

int degree[N];
vector<int> top;
void topsort(LGraph G)
{
    for (int i = 1; i <= G.vexnum; i++)
    {
        degree[i] = 0;
    }

    for (int i = 1; i <= G.vexnum; i++)
    {
        for (ArcNode *p = G.vetexList[i].firstArc; p; p = p->next)
        {
            int v = p->adjvex;
            degree[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        top.push_back(tmp);
        for (ArcNode *p = G.vetexList[tmp].firstArc; p; p = p->next)
        {
            int v = p->adjvex;
            degree[v]--;
            if (degree[v] == 0)
                q.push(v);
        }
    }
    for (int i = 0; i < top.size(); i++)
    {
        cout << top[i] << " ";
    }
    puts("");
    find(G, top);
}

int main()
{
    int n, m;
    cin >> n >> m;
    LGraph G;
    create(G, n, m);
    topsort(G);
    return 0;
}