#include "iostream"
using namespace std;
int a[100];
int Partition(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
int Partition2(int a[],int low,int high)
{
	int rand_Index = low + rand()%(high-low+1);
	swap(a[rand_Index],a[low]);
	int pivot=a[low];
	int i=low;
	for(int j=low+1;j<=high;j++)
		if(a[j]<pivot)
			swap(a[++i],a[j]);
	swap(a[i],a[low]);
	return i;
}
int Partition3(int a[],int low,int high)
{
	int rand_Index = low + rand()%(high-low+1);
	swap(a[rand_Index],a[low]);
	int pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>pivot)high--;
		a[low]=a[high];
		while(low<high&&a[low]<pivot)low++;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition3(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a, pivot+1, high);
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    QuickSort(a, 1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
