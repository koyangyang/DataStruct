//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void initArray(int a[],int n)
{
    for(int i=0;i<10;i++)
        //a[i]=(rand() % (10-1))+ 1;
        a[i]=i;
}

//int BSearch(int a[],int low,int high,int key)
//{
//    int mid=(low+high)/2;
//    if(a[mid]==key) return mid;
//    if (a[mid]>key) return BSearch(a,low,mid-1,key);
//    else return BSearch(a,mid+1,high,key);
//}

int BSearch(int a[],int low,int high,int key)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key) return mid;
        if (a[mid]>key) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

signed main() {
    int a[10];
    initArray(a,10);
    cout << BSearch(a,0,9,7);
    return 0;
}