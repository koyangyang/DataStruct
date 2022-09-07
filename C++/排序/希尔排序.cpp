//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void shellSort(int a[],int n)
{
    int i=0,j=0;
    for(int dk=n/2; dk>=1; dk=dk/2)//步长变化
    {
        for(int i=dk+1;i<=n;++i)
            if(a[i]<a[i-dk])//将a[i]插入有序增量子表
            {
                a[0]=a[i];//暂存在a[0]
                for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
                    a[j+dk]=a[j];//记录后移，查找插入位置
                a[j+dk]=a[0];//插入
            }
    }
}

signed main() {
    int n;
    cin>>n;
    int a[100010];
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    shellSort(a,n);
    for (int i = 1; i <= n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}