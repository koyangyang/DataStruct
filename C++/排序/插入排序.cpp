//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void InsertSort(int a[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            a[0]=a[i];
            for(j=i-1;a[0]<a[j];j--)
                a[j+1]=a[j];
            a[j+1]=a[0];
        }
    }
}

signed main() {
    int n;
    cin>>n;
    int a[1010];
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    InsertSort(a,n);
    for (int i = 1; i <= n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}