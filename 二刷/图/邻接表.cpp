struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
} ArcNode;
struct VNode
{
    int v;
    struct ArcNode *firstarc;
} VNode, Adjlist[MaxSize];
struct LGraph
{
    int arcnum, vexnum;
    Adjlist vexlist;
} LGraph;