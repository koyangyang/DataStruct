vector<int> TopSort(LGraph G)
{
    vector<int> degree(G.vexnum + 1, 0);
    vector<int> topsort;
    int cnt = 0;
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (ArcNode *p = G.vexlist[i].firstarc; p; p = p->next)
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
        int t = q.front();
        q.pop();
        topsort.push_back(t);
        cnt++; //计数器+1
        for (ArcNode *p = G.vexlist[t].firstarc; p; p = p->next)
        {
            int v = p->adjvex;
            degree[v]--;
            if (degree[v] == 0)
                q.push(v);
        }
    }
    if (cnt < G.vexnum)
        return NULL;
    return topsort;
}