//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "queue"


int* vis=new int(MaxSize);
int* d=new int(MaxSize);
int* path=new int(MaxSize);
queue<int> Q;
void BFS_MIN_Distance(LGraph G,int u)
{
    for(int i=0;i<G.vexnum;i++)
    {
        d[i]=0x3f;//无穷大
        path[i]=-1;//初始化路径
    }
    d[u]=0;//初始化第一个节点
    vis[u]=true;
    Q.push(u);
    while (!Q.empty())
    {
        int t=Q.front();Q.pop();
        for(ArcNode *p=G.vexlist[t].firstarc;p;p=p->next)
        {
            int v=p->adjvex;//获取节点编号
            if(!vis[v])
            {
                d[v]=d[t]+1;//距离加1
                path[v]=t;//将路径指向上一个节点
                vis[v]=true;//修改访问数组
                Q.push(v);//压入队列
            }//if
        }//for
    }//while
}

int main() {
    cout << "AC！" << endl;
    return 0;
}