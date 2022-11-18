int *vis = new int[N];
void DFS(LGraph G, int u)
{
    visit(u);
    vis[u] = 1;
    for (ArcNode *p = G.vexlist[u].firstarc; p; p = p->next)
    {
        int v = p->adjvex;
        if (vis[v] == 0)
            DFS(G, v);
    }
}
void DFS_Travel(LGraph G)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (vis[i] == 0)
            DFS(G, i);
    }
}