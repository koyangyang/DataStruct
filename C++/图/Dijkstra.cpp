//#include"bits/stdc++.h"
#include "iostream"
using namespace std;
#define INF 0x3f
const int N=103;
int matrix[N][N],dis[N],n;
bool vis[N];
int main()
{
	cin>>n;//����ڵ����
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>matrix[i][j];//���������ĳ�ʼ����
	}
	for(int i=1;i<=n;i++) dis[i]=matrix[1][i];
	for(int i=1;i<=n;i++){
		int minn=INF,k;//minnѡ��dis������û�б���ǵ���Сֵ��kΪ�ýڵ�ı��
		for(int j=1;i<=n;i++){//����dis����
			if(!vis[j]&&minn>dis[j])
			{
				k=j;
				minn=dis[j];
			}
		}
		vis[k]=1;
		for(int j=1;j<=n;j++){//ʹ��k�ڵ����dis����
			if(!vis[j]&&dis[j]>dis[k]+matrix[k][j])
			{
				dis[j]=dis[k]+matrix[k][j];
			}
		}
	}
	return 0;
}
