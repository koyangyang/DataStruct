//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Binary_Search(int a[],int low,int high,int key)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key) return mid;
        if(a[mid]>key) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main() {
    cout << "AC！" << endl;
    return 0;
}