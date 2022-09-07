//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swapitem(int a[],int len)
{
    int low=0,high=len-1,mid=0;
    while (low<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main() {
    int a[]={2,0,2,1,1,0};
    swapitem(a,6);
    for (int i = 0; i < 6; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}