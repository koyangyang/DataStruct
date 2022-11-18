#include <bits/stdc++.h>
using namespace std;
void exchange(int a[],int low,int high)
{
    while(low<high)
    {
        while(low<high&&a[high]%2==0)high--;
        while(low<high&&a[low]%2==1)low++;
        swap(a[low],a[high]);
    }
}
int main() {
    int a[]={0,2,3,4,5,6,9,11};
    exchange(a,1,7);
    for (int i = 1; i < 8; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}