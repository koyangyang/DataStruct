//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void SelectSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)//从0开始遍历到倒数第二个元素
    {
        int min=i;
        for (int j = i+1; j < n; ++j)
            if(a[j]<a[min])
                min=j;//记录最小元素位置
        if (min!=i)swap(a[min],a[i]);//交换最小元素
    }
}

signed main() {
    int n;
    cin>>n;
    int a[1010];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    SelectSort(a,n);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}