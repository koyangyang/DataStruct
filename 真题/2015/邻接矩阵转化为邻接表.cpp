//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void translate(int a[][],int m,int n,LinkList[])
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if(a[i][j]==1)
            {
                LinkList p=(LinkList)malloc(sizeof(LNode));
                p->data=j;
                p->next=NULL;
                LinkList[i]->first->next=p;
                LinkList[i]->first=p;
            }
        }
}

void Matrix_to_Vector(MGraph G,LGraph G1)
{
    G1.arcnum=G.arcnum,G1.vexnum=G1.vexnum;
    for (int i = 1; i <= G1.vexnum ; ++i)
        G1.vexlist[i].firstarc=NULL;
    for (int i = 1; i <=G1.vexnum ; ++i)
        for (int j = 1; j <=G1.vexnum ; ++j) {
            if(G.arcs[i][j])
            {
                //采用头插法
                ArcNode *p=new ArcNode;
                p->adjvex = j;
                p->next=G1.vexlist[i].firstarc;
                G1.vexlist[i].firstarc=p;
            }
        }
}

int main() {
    cout << "AC！" << endl;
    return 0;
}