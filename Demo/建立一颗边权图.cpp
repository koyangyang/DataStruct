#include "iostream"
using namespace std;
const int N = 100;
typedef struct Edge
{
    int u;
    int v;
    int cost;
} Edge;

typedef struct Graph
{
    Edge edges[N];
    int vexnum, arcnum;
} Graph;
void BuildGraph(Graph G)
{
    int n, u, v, cost;
    G.vexnum = 0;
    G.arcnum = 0;
    cin >> n;
    while (n--)
    {
        cin >> u >> v >> cost;
        G.edges[G.arcnum].u = u;
        G.edges[G.arcnum].v = v;
        G.edges[G.arcnum].cost = cost;
        G.arcnum++;
    }
}

main()
{
    Graph G;
    BuildGraph(G);
    for (int i = 0; i < G.arcnum; i++)
    {
        cout << G.edges[i].u << " " << G.edges[i].v << endl;
    }
}