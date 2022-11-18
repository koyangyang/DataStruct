#define N 100
int *root = new int[N];
int FindRoot(int x)
{
    while (root[x] != x)
        x = root[x];
    return x;
}
void Union(int x, int y)
{
    root[y] = x;
}
void init(int n)
{
    for (int i = 0; i <= n; i++)
        root[i] = i;
}
typedef struct Edge
{
    int u;
    int v;
    int c;
} Edge;
typedef struct EGraph
{
    int vexnum, arcnum;
    Edge edges[N];
};
void Kruskal(EGraph G)
{
    EGraph NG;
    NG.arcnum = 0;
    NG.vexnum = G.vexnum;
    QuickSort(G.edges);
    for (int i = 0; i < G.arcnum; i++)
    {
        int u = G.edges[i].u;
        int v = G.edges[i].v;
        int x = FindRoot(u), y = FindRoot(v);
        if (x != y) //如果x、y不属于一个连通图
        {
            NG.edges[NG.arcnum].u = u;
            NG.edges[NG.arcnum].v = v;
            NG.arcnum++;
            Union(x, y); //将x、y并到一个集合中
        }
    }
}