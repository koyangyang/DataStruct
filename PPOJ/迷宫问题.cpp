#include "iostream"
#include"queue"
using namespace std;

int m,n;
int mi[5][5];
bool vis[5][5];
const int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
typedef struct point
{
	int x;int y;
	int step;
};
int ex,ey,estep;

void BFS(int x,int y)
{
	queue<point> q;
	point tmp;
	tmp.x=x;tmp.y=y;tmp.step=0;
	vis[x][y]=true;
	q.push(tmp);
	while(!q.empty()){
		int n_x=q.front().x;
		int n_y=q.front().y;
		int n_step=q.front().step+1;
		for(int i=0;i<4;i++){
			int nowx=n_x+dic[i][0];
			int nowy=n_y+dic[i][1];
			if(nowx>=0&&nowx<m&&nowy>=0&&nowy<n&&mi[nowx][nowy]!=2&&!vis[nowx][nowy])
			{
				if(nowx==ex&&nowy==ey)
				{
					estep=n_step;
					return;
				}
				vis[nowx][nowy]=true;
				point now;
				now.x=nowx;
				now.y=nowy;
				now.step=n_step;
				q.push(now);
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
			cin>>mi[i][j];
	cin>>ex>>ey;
	BFS(0,0);
	cout<<estep;
	return 0;
}
