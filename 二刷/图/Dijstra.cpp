#include "bits/stdc++.h"
using namespace std;
//#define INF 0x3f
const int N = 103;
int matrix[N][N], dis[N], n, path[N];
bool vis[N];
int main()
{
    stack<int> stk;
    cin >> n; //读入节点个数
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j]; //读入各个点的初始距离
        }
        path[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = matrix[1][i];
        if (matrix[1][i] != 9999)
            path[i] = 1;
    }
    vis[1] = true;
    for (int i = 1; i < n; i++)
    {
        int minn = 9999, k; // minn选出dis数组中没有被标记的最小值，k为该节点的编号
        for (int j = 1; j <= n; j++)
        { //遍历dis数组
            if (!vis[j] && minn > dis[j])
            {
                k = j;
                minn = dis[j];
            }
        }
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        { //使用k节点更新dis数组
            if (!vis[j] && dis[j] > dis[k] + matrix[k][j])
            {
                dis[j] = dis[k] + matrix[k][j]; //更新距离
                path[j] = k;                    // path数组进行保存路径
            }
        }
    }
    for (int i = 2; i <= n; i++) //输出到每个节点的最短路径
    {
        int x = i;
        stk.push(i);
        while (path[x] != -1) //通过path数组是进行逆向保存
        {
            stk.push(path[x]);
            x = path[x];
        }
        while (!stk.empty()) //存入栈中进行反转输出
        {
            int t = stk.top();
            stk.pop();
            cout << t << " ";
        }
        cout << "最小距离" << dis[i];
        puts("");
    }
    return 0;
}
/*
4
9999 1 4 9999
9999 9999 2 7
9999 9999 9999 3
9999 9999 9999 9999
/*