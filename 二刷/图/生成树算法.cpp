typedef struct BTree
{
    BTree(int d, struct BTree *l, struct BTree *s) : data(d), lson(l), sibiling(s) {}
    int data;
    struct BTree *lson, *sibiling;
};

BTree *DFSForest(LGraph G)
{
    BTree *root = NULL;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < G.vexnum; i++)
    {
        if (vis[i] == 0)
        {
            if (root)
                root = DFSTree(G, i);
            else
            {
                root->sibiling = DFSTree(G, i);
                root = root->sibiling;
            }
        }
    }
}

BTree *DFSTree(LGraph G, int u)
{
    BTree *root = new BTree(u, NULL, NULL);
    vis[u] = true;
    bool first = true;
    for (ArcNode *p = G.vexlist[u].firstarc; p; p = p->next)
    {
        int v = p->adjvex;
        if (vis[p] == 0)
        {
            BTree *t = DFSTree(G, v);
            if (first)
            {
                root->lson = t;
                first = false;
            }
            else
            {
                root->sibiling = t;
                root = root->sibiling;
            }
        }
    }
}
