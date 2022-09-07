#include<bits/stdc++.h>
using namespace std;
struct marray{
	vector<int> data;
	int len;
	int k;
	marray(int n,int m)
	{
		len=n;
		k=m;
		for(int i=0;i<len;i++)
		{
			int temp;
			cin>>temp;
			data.push_back(temp);
		}
	}
	int mfind(int left,int right,int k)
	{
		if(left>right)
			return -1;
		int key=data[left];
		int low,high;
		low=left;
		high=right;
		while(low<high)
		{
			while(low<high&&data[high]>=key)
			{
				high--;
			}
			data[low]=data[high];
			while(low<high&&data[low]<=key)
			{
				low++;
			}
			data[high]=data[low];
		}
		data[low]=key;
		int num=right-low+1;
		printf("%d %d\n",num,data[low]);
		if(num>k)
		{
			return mfind(low+1,right,k);
		}
		else if(num<k)
		{
			return mfind(left,low-1,k-num);
		}
		return data[low];
	}
};

int main()
{
	int m,n;
	cin>>m>>n;
	marray p(m,n);
	cout<<p.mfind(0,m-1,n)<<endl;
	return 1;
}
