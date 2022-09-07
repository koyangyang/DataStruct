struct Graph
{
    int NodeNum;//图中节点数目
    vector<int> adjList[NodeNum];//每个节点的邻接表
}*G;
bool visit[G->NodeNum];//记录访问数组
int path[G->NodeNum],cnt=0;//path用来记录路径，cnt记录步长
void Findpath_S_T(int t)
{
    if(visit[t]) return;//如果t已经访问直接返回
    path[cnt++] = t;//将当前节点加入path数组
    visit[t]=1;//打上访问标记
    if(t==s)//已经到达s节点，输出path数组并返回
    {
        for(int i=1;i<=cnt;i++)
            cout<<path[i];
        visit[t]=0;//遍历结束后标记置0
        cnt--;//部署-1
        return;
    }
    for(int i=0;i<G->adjList[t].size();i++)//遍历与t相邻的所有节点
    {
        int to=G->adjList[t][i];
        Findpath_S_T(to);//继续寻找下一个节点
    }
    visit[t]=0;//遍历结束后标记置0
    cnt--;
    return;
}