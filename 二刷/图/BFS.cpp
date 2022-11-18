int m,n;
int mi[5][5];
bool vis[5][5];
const int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int ex,ey,estep;

void BFS(int x,int y,int k)
{
	queue<pair<pair<int,int>,int>> q;
	vis[x][y]=true;
	q.push({{x,y},0});
	while(!q.empty()){
		int n_x=q.front().first.first;
		int n_y=q.front().first.second;
		int n_step=q.front().second+1;
		for(int i=0;i<4;i++){
			int nowx=n_x+dic[i][0];
			int nowy=n_y+dic[i][1];
			if(nowx>=0&&nowx<m&&nowy>=0&&nowy<n&&mi[nowx][nowy]!=2&&!vis[nowx][nowy])
			{
				if(nowx==ex&&nowy==ey)
				{
					estep=n_step;
					if(estep<=k)
						cout<<"YES"<<endl;
					else
						cout<<"NO"<<endl;
					return;
				}
				vis[nowx][nowy]=true;
				q.push({{nowx,nowy},n_step});
			}
		}
		q.pop();
	}
}