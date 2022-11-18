void FindPath(LGraph G,int u,int v,int path[],int d)
{
    int w, i;
    ArcNode *p;
    d++;
    path[d] = u;
    vis[u] = 1;
    if(u==v)
        print(path[]);
    p = G.vexlist[u].firstarc;
    while(p)
    {
        w = p->adjvex;
        if(vis[w]==0)
            FindPath(G, w, v, path, d);
        p = p->next;
    }
    vis[u] = 0;
}