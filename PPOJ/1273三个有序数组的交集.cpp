#include<bits/stdc++.h>
using namespace std;
class solution{
	int a,b,c;
	vector<int> data1,data2,data3;
public:
	solution(int x,int y,int z)
	{
		a=x;b=y;c=z;
		data1.resize(a);
		data2.resize(b);
		data3.resize(c);
		for(int i=0;i<a;i++)
		{
			scanf("%d",&data1[i]);
		}
		for(int i=0;i<b;i++)
		{
			scanf("%d",&data2[i]);
		}
		for(int i=0;i<c;i++)
		{
			scanf("%d",&data3[i]);
		}
	}
	void mfind()
	{
		int i,j,k;
		i=j=k=0;
		int flag=0;
		while(i<a&&j<b&&k<c)
		{
			if(data1[i]==data2[j]&&data2[j]==data3[k])
			{
				if(flag==1)
				{
					printf(" ");
				}
				
				printf("%d",data1[i]);
				flag=1;
				++i;++j;++k;
			}
			else
			{
				int temp=min(data1[i],min(data2[j],data3[k]));
				if(data1[i]==temp)
					++i;
				if(data2[j]==temp)
					++j;
				if(data3[k]==temp)
					++k;
			}
		}
		printf("\n");
	}
};
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	solution p(x,y,z);
	p.mfind();
	return 1;
}
