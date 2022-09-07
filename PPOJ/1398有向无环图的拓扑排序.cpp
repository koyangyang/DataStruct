//这道题说明了用栈或队列，然后我一开始就从小开始记录输出。因为答案不唯一，实际上最后发现是用栈保存，每次遇到新的入度为0的push进栈
#include<bits/stdc++.h>
using namespace std;
struct eage{
	int from;
	int to;
	eage(int a,int b): from(a),to(b) {}
};
class graph{
	int **matrix;
	int num;
	vector<int> vis;
	vector<vector<eage>> Eages;
	vector<int> degree;
public:
	graph(int n)
	{
		num=n;
		matrix=new int*[n];
		vis.resize(num,0);
		Eages.resize(num);
		degree.resize(num,0);
		for(int i=0;i<num;i++)
		{
			matrix[i]=new int[num];
		}
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
			{
				cin>>matrix[i][j];
				if(matrix[i][j]==1)
				{
					Eages[i].push_back({i,j});
					degree[j]++;
				}
				
			}
		}
	}
	void top_sort()
	{
		vector<int> mem;
		stack<int> stk;
		for(int i=0;i<num;i++)
		{
			if(degree[i]==0)
				stk.push(i);
		}
		while(!stk.empty())
		{
			int p=stk.top();
			vis[p]=1;
			mem.push_back(p);
			stk.pop();
			for(int i=0;i<Eages[p].size();i++)
			{
				degree[Eages[p][i].to]--;
				if(vis[Eages[p][i].to]==0&&degree[Eages[p][i].to]==0)
					stk.push(Eages[p][i].to);
			}
		}
		if(mem.size()==num)
		{
			for(auto p:mem)
				cout<<p<<" ";
			cout<<endl;
		}
		else
			cout<<"ERROR"<<endl;
	}
	
};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		graph p(n);
		p.top_sort();
	}
	return 1;
}

