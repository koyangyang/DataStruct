#include "iostream"
using namespace std;

void HelanFlag(int a[],int n)
{
	int mid = 0,low=0,tmp=0,high=n;
	while (low <= high)
	{
		if(a[mid]==0)
		{
			swap(a[mid],a[low]);
			low++;
			mid++;
		}
		else if(a[mid]==2)
		{
			mid++;
		}
		else if(a[mid]==1){
			swap(a[mid],a[high]);
			high--;
		}
	}
}

int main()
{
	int a[] = {2,0,2,1,1,0,2,1,0,1,2,0};
	HelanFlag(a,11);
	for (int i = 0; i < 12; i++)
		cout << a[i] << " ";
	return 0;
}
