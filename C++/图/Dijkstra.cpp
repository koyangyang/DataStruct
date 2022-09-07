//#include"bits/stdc++.h"
#include "iostream"
using namespace std;
#define INF 0x3f
const int N=103;
int matrix[N][N],dis[N],n;
bool vis[N];
int main()
{
	cin>>n;//读入节点个数
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>matrix[i][j];//读入各个点的初始距离
	}
	for(int i=1;i<=n;i++) dis[i]=matrix[1][i];
	for(int i=1;i<=n;i++){
		int minn=INF,k;//minn选出dis数组中没有被标记的最小值，k为该节点的编号
		for(int j=1;i<=n;i++){//遍历dis数组
			if(!vis[j]&&minn>dis[j])
			{
				k=j;
				minn=dis[j];
			}
		}
		vis[k]=1;
		for(int j=1;j<=n;j++){//使用k节点更新dis数组
			if(!vis[j]&&dis[j]>dis[k]+matrix[k][j])
			{
				dis[j]=dis[k]+matrix[k][j];
			}
		}
	}
	return 0;
}
