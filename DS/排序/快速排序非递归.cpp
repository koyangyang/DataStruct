#include <bits/stdc++.h>
using namespace std;
int Proportion(int a[],int low,int high)
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
void QuickSort(int a[],int low,int high)
{
    stack<pair<int,int>> stk;
    stk.push({low,high});
    while(!stk.empty())
    {
        int x=stk.top().first,y=stk.top().second;
        stk.pop();
        int pivot=Proportion(a, x, y);
        if(x<pivot-1)stk.push({x, pivot-1});
        if(pivot+1<y)stk.push({pivot+1,y});
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