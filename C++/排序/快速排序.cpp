//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Partition(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while (low<high&&a[high]>=pivot) high--;
        a[low]=a[high];
        while (low<high&&a[low]<=pivot) low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=Partition(a,low,high);
        QuickSort(a,low,mid-1);
        QuickSort(a,mid+1,high);
    }
}

signed main() {
    int n;
    cin>>n;
    int a[100010];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}