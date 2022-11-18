#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

typedef struct ArcNode {
  int adjvex;
  ArcNode *next;
} ArcNode;

typedef struct {
  int data;
  ArcNode *firstArc;
} VNode;

typedef struct {
  VNode vetexList[N];
  int arcnum, vexnum;
} LGraph;

// 创建邻接表
void create(LGraph &G, int n, int m) {
  G.arcnum = m;
  G.vexnum = n;
  for (int i = 1; i <= n; i += 1) {
    G.vetexList[i].data = i;
    G.vetexList[i].firstArc = NULL;
  }

  for (int i = 0; i < m; i += 1) {
    int s, e;
    cin >> e >> s;
    ArcNode *p = new ArcNode;
    p->adjvex = e;
    p->next = G.vetexList[s].firstArc;
    G.vetexList[s].firstArc = p;
  }
}

struct Money {
  int money;
  int vex;
};

int TopuSort(LGraph &G) {
  vector<int> degree(N, 0);
  int result = 0;
  for (int i = 1; i <= G.vexnum; i += 1) {
    for (ArcNode *p = G.vetexList[i].firstArc; p != NULL; p = p->next) {
      degree[p->adjvex]++;
    }
  }
  queue<Money> q;
  for (int i = 1; i <= G.vexnum; i += 1) {
    if (!degree[i]) {
      Money temp;
      temp.money = 888;
      temp.vex = i;
      q.push(temp);
      result += temp.money;
    } // degree==0 into queue
  }

  while (!q.empty()) {
    Money front = q.front();
    q.pop();
    for (ArcNode *p = G.vetexList[front.vex].firstArc; p != NULL; p = p->next) {
      if (!--degree[p->adjvex]) {
        Money temp;
        temp.money = front.money + 1;
        temp.vex = p->adjvex;
        q.push(temp);
        result += temp.money;
      }
    }
  }
  for (int i = 1; i <= G.vexnum; i += 1) {
    if (degree[i])
      return -1;
  }
  return result;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    LGraph G;
    create(G, n, m);
    cout << TopuSort(G) << endl;
  }
  return 0;
}