int d[n][n];
// 算法结束后，d[a][b]表示a到b的最短距离
void floyd(int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int findcenter(int n)
{
    //初始化：INF为负无穷
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    floyd(n);
    int center = 1, dis = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int maxdis = 0, id;
        for (int j = 1; j <= n; j++)
        {
            maxdis = max(maxdis, d[i][j]); //找到该城市到最远城市距离
        }
        if (dis > maxdis) //更新答案
        {
            dis = maxdis;
            center = i;
        }
    }
    cout << center << dis; //输出中心城市和中心城市到最远城市的距离
}