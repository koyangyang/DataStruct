#include<bits/stdc++.h>
using namespace std;
struct eage{
	int from;
	int dst;
	int val;
	int trans;
	eage(int a,int b,int c,int d)
	{
		from=a;
		dst=b;
		val=c;
		trans=d;
	}
};
class mset{
	vector<int> rank;
	vector<int> parent;
	int num;
	vector<eage> Eages;
public:
	mset(int n)
	{
		num=n;
		for(int i=0;i<n;i++)
		{
			rank.push_back(1);
			parent.push_back(i);
		}
		int bian=n*(n-1)/2;
		int a,b,c,d;
		for(int i=0;i<bian;i++)
		{
			cin>>a>>b>>c>>d;
			Eages.push_back({a-1,b-1,c,d});
			if(d==1)
			{
				Union(a-1,b-1);
			}
		}
	}
	int MINroad()
	{
		sort(Eages.begin(),Eages.end(),[&](const eage &u,const eage &v)
			{
				return u.val<v.val;
			});
		int res=0;
		for(int i=0;i<Eages.size();i++)
		{
			if(check())
				return res;
			if(Eages[i].trans!=1)
			{
				int x=find(Eages[i].from);
				int y=find(Eages[i].dst);
				if(x!=y)
				{
					Union(Eages[i].from,Eages[i].dst);
					res+=Eages[i].val;
				}
			}
		}
		return res;
	}
	bool check()
	{
		for(int i=0;i<num-1;i++)
		{
			if(parent[i]!=parent[i+1])
				return false;
		}
		return true;
	}
	int find(int x)
	{
		while(x!=parent[x])
		{
			x=find(parent[x]);
		}
		return x;
	}
	void Union(int x,int y)
	{
		int px=find(x);
		int py=find(y);
		if(px!=py)
		{
			if(rank[px]>rank[py])
			{
				parent[py]=px;
			}
			else
			{
				parent[px]=y;
				if(rank[px]==rank[py])
					rank[py]++;
			}
		}
	}
};


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		mset p(n);
		cout<<p.MINroad()<<endl;
	}
	return 1;
}
