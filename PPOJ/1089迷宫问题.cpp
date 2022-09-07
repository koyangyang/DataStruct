//DFS无法保证最短路，就算用贪心右下也会被卡样例
//BFS能保证最短路径，因为递归深度和队列先进先出的特性，但是我们需要一个备忘录从后保存其唯一前驱节点，反之用数组的形式从前往后难以判断
#include<bits/stdc++.h>
using namespace std;
class solution{
	int matrix[5][5];
	int visit[6][6];
	int dirction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
	int flag=0;
	vector<pair<int,int>> mem; //用于DFS保存路径
	struct road{
		int x;
		int y;
	};
	road Road [5][5];
public:
	solution() //初始化
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cin>>matrix[i][j];
				visit[i+1][j+1]=0;
			}
		}
	}
	void BFS()
	{
		queue<pair<int,int>> mque;
		mque.push({0,0});
		visit[1][1]=1;
		Road[0][0].x=-1;
		Road[0][0].y=-1;
		while(!mque.empty())
		{
			auto temp=mque.front();
			if(temp.first==4&&temp.second==4)
			{
				print(4,4);
				return ;
			}
			
			mque.pop();
			int xtemp,ytemp;
			for(int i=0;i<4;i++) //向四个方向搜索
			{
				xtemp=temp.first+dirction[i][0];
				ytemp=temp.second+dirction[i][1];
				if(!(xtemp<0||xtemp>4)&&!(ytemp<0||ytemp>4)&&matrix[xtemp][ytemp]!=1&&visit[xtemp+1][ytemp+1]==0)
				{ //满足条件则置已访问，并且记录前驱
					mque.push({xtemp,ytemp});
					visit[xtemp+1][ytemp+1]=1;
					Road[xtemp][ytemp].x=temp.first;
					Road[xtemp][ytemp].y=temp.second;
				}
			}
			
		}
	}
	void print(int x,int y) //递归打印
	{
		if(x==-1&&y==-1) return ;
		print(Road[x][y].x,Road[x][y].y);
		cout<<"("<<x<<", "<<y<<")"<<endl;
	}
	void DFS(int x,int y,int fromx,int fromy)
	{ //三色标记法
		if(flag==1)
			return ;
		if((x<0||x>4)||(y<0||y>4)) //越界返回
			return ;
		mem.push_back({x,y});
		if(visit[x+1][y+1]==0) //从白色变成灰色·，说明在回溯中
			visit[x+1][y+1]=1;
		if(x==4&&y==4)
		{
			for(auto &temp:mem)
			{
				auto x_val=temp.first;
				auto y_val=temp.second;
				cout<<"("<<x_val<<", "<<y_val<<")"<<endl;
			}
			flag=1;
			return ;
		} //主要是不能访问来时的点，也不能访问回溯完成的点，也不能访问墙
		if(visit[x+2][y+1]!=2&&matrix[x+1][y]!=1&&!(x+1==fromx&&y==fromy))
			DFS(x+1,y,x,y);
		if(visit[x+1][y+2]!=2&&matrix[x][y+1]!=1&&!(x==fromx&&y+1==fromy))
			DFS(x,y+1,x,y);
		if(visit[x+1][y]!=2&&matrix[x][y-1]!=1&&!(x==fromx&&y-1==fromy))
			DFS(x,y-1,x,y);
		if(visit[x][y+1]!=2&&matrix[x-1][y]!=1&&!(x-1==fromx&&y==fromy))
			DFS(x-1,y,x,y);
		visit[x+1][y+1]=2;
		mem.pop_back(); //最后把走过的路pop出来，防止中间有多的路径输出
	}
};

int main()
{
	solution p;
	p.BFS();
	return 0;
}
