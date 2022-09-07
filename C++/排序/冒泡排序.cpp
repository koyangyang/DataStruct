//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void BubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)//从0开始，从前往后遍历
    {
        bool flag=false;
        for (int j = n-1; j > i; --j)//从倒数第一个位置开始，从后往前遍历
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
                flag=true;
            }
        if (!flag)//若一趟排序没有发生交换则提前开始
            return;
    }
}

signed main() {
    int n;
    cin>>n;
    int a[1010];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    BubbleSort(a,n);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}