#include "iostream"
#include"queue"
using namespace std;

int m,n;
int arcs[5][5];
bool vis[5][5];
const int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int fx,fy,estep;

void BFS(int x,int y,int k)//判断是否存在步长为k的路径
{
    queue<pair<pair<int,int>,int>> q;
    vis[x][y]=true;
    q.push({{x,y},0});//初始路径长为0
    while(!q.empty()){
        int xx=q.front().first.first;
        int yy=q.front().first.second;
        int nnstep=q.front().second+1;
        for(int i=0;i<4;i++){
            int nx=xx+dic[i][0];
            int ny=yy+dic[i][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&arcs[nx][ny]!=2&&!vis[nx][ny])
            {
                if(nx==fx&&ny==fy)
                {
                    estep=nnstep;
                    if(estep<=k)//是长度为k的路径则输出yes
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                    return;
                }
                vis[nx][ny]=true;
                q.push({{nx,ny},nnstep});
            }
        }
        q.pop();
    }
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
    BFS(0,0,8);
    cout<<estep;
    return 0;
}