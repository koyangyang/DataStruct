struct Edge{
    int u,v;//边的两个端点
};
struct Graph{
    int NodeNum,EdgeNum;//图中结点数目，边的数目
    Edge E[EdgeNum];//图中的每条边
}*G;
int f[G->NodeNum];//并查集的father数组
int _find(int x)//返回x节点的根节点编号，带路径压缩
{
    return x==f[x]?x:f[x]=_find(f[x]);
}
int CountCBlocks()
{
    for (int i = 0; i < G->NodeNum; ++i)
        f[i]=i;//初始化f数组，相当于初始时每个节点都是一个连通块
    int ans=G->NodeNum;//初始答案为点的数目
    for (int i = 0; i < G->EdgeNum; ++i) {
        //查询当前边的两个节点所属连通块编号
        int fu = _find(G->E[i].u),fv = _find(G->E[i].v);
        if(fu!=fv)//若不连通
        {
            ans--;//连通块-1
            f[fu]=fv;//将这两个连通块合并
        }
    }
    return ans;
}