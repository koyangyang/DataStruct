//DFS主要是利用递归标记油田，可以朝八个方向进行搜索
//BFS主要是队列辅助保存节点信息，一开始还以为像迷宫一样要记忆化搜索回溯
#include<bits/stdc++.h>
using namespace std;
const int dic[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
class solution{
    char **matrix;
    int m;
    int n;
    vector<vector<int>> vis;
public:
    solution(int a,int b)
    {
        m=a;
        n=b;
        vis.resize(m+10,vector<int>(n+10,0));
        matrix=new char*[m];
        for(int i=0;i<m;i++)
        {
            matrix[i]=new char[n];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
    }
    void DFS_travel()
    {
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='@'&&vis[i+1][j+1]==0)
                {
                    DFS(i,j);
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    void DFS(int posx,int posy)
    {
        if(vis[posx+1][posy+1]==1)
            return ;
        vis[posx+1][posy+1]=1;
        for(int i=0;i<8;i++)
        {
            int x=dic[i][0]+posx;
            int y=dic[i][1]+posy;
            if(x>=0&&x<m&&y>=0&&y<n&&matrix[x][y]=='@')
                DFS(x,y);
        }
    }
    void BFS_travel()
    {
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='@'&&vis[i+1][j+1]==0)
                {
                    BFS(i,j);
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    void BFS(int posx,int posy)
    {
        queue<pair<int,int>> mem;
        mem.push({posx,posy});
        vis[posx+1][posy+1]=1;
        while(!mem.empty())
        {
            auto temp=mem.front();
            mem.pop();
            for(int j=0;j<8;j++)
            {
                int x=temp.first+dic[j][0];
                int y=temp.second+dic[j][1];
                if(vis[x+1][y+1]==0&&x>=0&&x<m&&y>=0&&y<n&&matrix[x][y]=='@')
                {
                    mem.push({x,y});
                    vis[x+1][y+1]=1;
                }
            }
        }
    }
};

int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m==0&&n==0)
            break;
        solution p(m,n);
        p.BFS_travel();
    }
    return 1;
}