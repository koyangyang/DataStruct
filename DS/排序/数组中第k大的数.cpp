#include "iostream"
using namespace std;

int mfind(int data[],int left,int right,int k)
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
	int num=right-low+1;//计算当前排序中间元素是第几大元素
	if(num>k)//如果当前差距大于k，必定在右区间找
	{
		return mfind(data,low+1,right,k);
	}
	else if(num<k)//如果差距小于k，必定在左区间找
	{
		return mfind(data,left,low-1,k-num);
	}
	return data[low];
}

int main()
{
	return 0;
}
