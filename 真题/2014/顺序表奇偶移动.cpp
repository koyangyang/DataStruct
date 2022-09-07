//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void exchange(int a[],int n)
{
    int i=0,j=n-1,temp;
    while(i<j)
    {
        while(i<j&&a[i]%2==0) i++;
        while(i<j&&a[j]%2!=0) j--;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

int main() {
    int a[10]={1,2,3,4,5,6,7,8,9};
    exchange(a,10);
    for (int i = 0; i < 10; ++i)
        cout<<a[i]<<" ";
    return 0;
}