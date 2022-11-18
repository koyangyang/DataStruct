#include <bits/stdc++.h>
using namespace std;
bool judge(int a[],int n)
{
    if(n%2==0)
    {
        if(a[n/2]<a[n]) return false;
        for(int k=n/2-1;k>=1;k--)
            if(a[k]<a[k*2]||a[k]<a[2*k+1])
                return false;
    }else
    {
        for(int k=n/2;k>=1;k--)
            if(a[k]<a[k*2]||a[k]<a[2*k+1])
                return false;
    }
}
int main() {

    return 0;
}