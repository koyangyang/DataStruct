//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

const int MaxSize=200;
//定义边节点
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
//定义点节点
typedef struct {
    int data;
    struct ArcNode *firstarc;
}VNode;
//定义邻接表
typedef struct {
    VNode vexlist[MaxSize];
    int arcnum,vexnum;
}LGraph;
//使用拓扑排序判断图是否有环
bool JudgeDAGbyTopSort(LGraph G)
{
    queue<int> q;
    //cnt统计遍历到的节点个数
    //indegree数组保存每个节点的入度
    int cnt=0,indegree[MaxSize]={0};
    //统计每个节点的入度
    for (int i = 1;  i<=G.vexnum; i++) {
        ArcNode *p=G.vexlist[i].firstarc;
        while(p)
        {
            indegree[p->adjvex]++;
            p=p->next;
        }
    }
    //度为0的节点全部入队
    for (int i = 0; i <=G.vexnum ; ++i)
        if(indegree[i]=0)
            q.push(i);
    while(!q.empty())
    {
        //取出队首元素
        int now=q.front();q.pop();
        //计数器+1
        cnt++;
        for (ArcNode *p=G.vexlist[now].firstarc;p;p=p->next)
        {
            int u=p->adjvex;
            //入度减一，若减一后变为0，加入到队列
            if(!(--indegree[u]))
                q.push(u);
        }
    }//while
    //若拓扑排序结束后cnt小于图的节点数
    //那么图中必定有环(环不存在度为0的节点)
    if(cnt<G.vexnum) return false;
    else true;
}


int main() {
    cout << "AC！" << endl;
    return 0;
}