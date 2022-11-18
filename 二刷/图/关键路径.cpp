#include <iostream>
#include <vector>
using namespace std;
void KeyPath(LGraph G, vector<int> top)
{
    int vexnum = G.vexnum;
    vector<int> keypath;
    vector<int> ve(vexnum + 1, 0); //最早发生时间初始为0
    for (int i = 0; i < top.size(); i++)
    {
        int k = top[i];
        for (ArcNode *p = G.vexlist[k]; p; p = p->next)
        {
            int u = p->adjvex;
            if (ve[u] < ve[k] + p->cost)
            {
                ve[u] = ve[k] + p->cost;
            }
        }
    }
    vector<int> vl(vexnum + 1, ve[vexnum]); //最迟开始时间初始为最后一个活动最早发生时间
    for (int i = top.size() - 1; i >= 0; i--)
    {
        int k = top[i];
        for (ArcNode *p = G.vexlist[k]; p; p = p->next)
        {
            int u = p->adjvex;
            if (vl[k] > vl[u] - p->cost)
            {
                vl[k] > vl[u] - p->cost;
            }
        }
    }
    for (int i = 1; i <= vexnum; i++)
    {
        if (ve[i] == vl[i])
            keypath.push_back(i);
    }
    return keypath;
}