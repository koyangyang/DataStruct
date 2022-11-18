#include "iostream"
#include"vector"
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

vector<point> stk;
int top=0;
void DFS(int x,int y)
{
	vis[x][y]=true;
	point tmp;
	tmp.x=x;tmp.y=y;tmp.step=0;
	stk.push_back(tmp);
	top++;
	if(x==ex&&y==ey)
	{
		for(int j=0;j<top;j++)
			cout<<stk[j].x<<stk[j].y<<" ";
			puts("");
			return ;
	}
	for(int i=0;i<4;i++){
			int nowx=x+dic[i][0];
			int nowy=y+dic[i][1];
			if(nowx>=0&&nowx<m&&nowy>=0&&nowy<n&&mi[nowx][nowy]!=2&&!vis[nowx][nowy])
			{
				DFS(nowx,nowy);
				vis[nowx][nowy]=false;
				stk.pop_back();
				top--;
			}
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
	DFS(0,0);
	return 0;
}
