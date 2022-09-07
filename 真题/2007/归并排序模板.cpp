//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int *tmp=(int *)malloc((100010+1)* sizeof(int));

void Merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    for(int i=0;i<=high;i++)
        tmp[i]=a[i];
    while(i<=mid&&j<=high)
        if(tmp[i]<=tmp[j]) a[k++]=tmp[i++];
        else a[k++]=a[j++];
    while(i<=mid) a[k++]=tmp[i++];
    while(j<=high) a[k++]=tmp[j++];
}

void MergeSort(int a[],int low,int high)
{
    if(low>=high)
        return;
    int mid=(low+high)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    Merge(a,low,mid,high);
}

signed main() {
    int n;
    cin>>n;
    int a[100010];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    MergeSort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}

