#include "iostream"
using namespace std;
int a[100];
int* tmp=new int[100];
void Merge(int a[],int low,int mid,int high)
{
    int idx=mid+1,k=low;
    for(int i=low;i<=high;i++)
        tmp[i]=a[i];
    while(low<=mid&&idx<=high)
    {
        if(tmp[low]<tmp[idx])a[k++]=tmp[low++];
        else a[k++]=tmp[idx++];
    }
    while(low<=mid)a[k++]=tmp[low++];
    while(idx<=high)a[k++]=tmp[idx++];
}
void MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    MergeSort(a, 1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}