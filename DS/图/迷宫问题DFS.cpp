#include "iostream"
#include"queue"
using namespace std;

int m,n;
int arcs[5][5];
bool vis[5][5];
const int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int fx,fy;
bool flag=false;
vector<pair<int,int>> path;

void DFS(int x,int y)
{
    if(flag) return;
    vis[x][y]=true;
    path.push_back({x,y});
    for(int i=0;i<4;i++){
        int nx=x+dic[i][0];
        int ny=y+dic[i][1];
        if(nx>=0&&nx<m&&ny>=0&&ny<n&&arcs[nx][ny]!=2&&!vis[nx][ny])
        {
            if(nx==fx&&ny==fy)
            {
                flag=true;
                for(auto i:path)
                {
                    cout<<i.first<<" "<<i.second<<endl;
                }
            }
            DFS(nx,ny);
        }
    }
    path.pop_back();
}

/*
5 5
1 1 2 2 1
1 1 1 1 1
2 2 2 1 2
2 2 2 1 2
2 2 2 1 1
4 4
*/

int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arcs[i][j];
    cin>>fx>>fy;
    DFS(0,0);
    return 0;
}