typedef struct status //状态表
{
    int v;   //来源点
    int w;   //权值
    int vis; //标记
} status;

void Prime(LGraph G)
{
    status sta[G.vexnum + 1];
    for (int i = 1; i <= G.vexnum; i++) //初始化状态表
    {
        sta[i].v = -1;
        sta[i].cost = INF;
        sta[i].vis = 0;
    }
    for (ArcNode *p = G.vexlist[1].firstarc; p; p = p->next) //初始化与1结点相连点
    {
        sta[p->adjvex].w = p->cost;
        sta[p->adjvex].v = 1;
    }
    sta[1].vis = 1;                    //标记1号结点
    for (int i = 1; i < G.vexnum; i++) //循环n-1次
    {
        int min = INF, idx = -1;
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (sta[j].cost < min)
            {
                min = sta[j].cost;
                idx = j;
            }
        }
        sta[idx].vis = 1;                                          //标记已访问结点
        for (ArcNode *p = G.vexlist[idx].firstarc; p; p = p->next) //更新状态表
        {
            if (sta[p->adjvex].cost < p->cost)
            {
                sta[p->adjvex].cost = p->cost;
                sta[p->adjvex].v = idx;
            }
        }
    }
}