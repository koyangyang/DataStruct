//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int MidFind(int a[],int low,int high,int key)
{
    int mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]==key) return mid;
        else if(a[mid]>key)
        {
            high=mid-1;
            mid=(low+high)/2;
        } else
        {
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return -1;
}

signed main() {
    int a[]={1,2,3,4,5,6,7,8,9,10};
    cout<<MidFind(a,0,9,51);
    return 0;
}