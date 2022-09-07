int FindRoot(int r)//并查集
{
    if(F[r]==r) return r;
    else return F[r]=FindRoot(F[r]);
}

void Kruskal(Graph G,Graph &T)
{
    T.vertex = G.vertex;//T的顶点集即为G的顶点集
    int m=G.arcnum;
    int edgenum = 0;
    Quick_Sort(G.edge,1,m);//对G的边进行由大到小快速排序
    for (int i = 1; i < m; ++i) {
        ///选择第i条边，并获得其端点(u,v)
        int u=G.edge[i].v,v=G.edge[i].v;
        int rootu=FindRoot(u);
        int rootv=FindRoot(v);
        if(rootu!=rootv)//两者不属于同一个连通分量
        {
            T.edge[++edgenum] = {u,v};//将该边放入T中
            F[rootu]=F[rootv];//将u,v所属连通分量连接成为一个
        }
    }
}