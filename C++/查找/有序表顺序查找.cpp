//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[10]={0,1,2,3,4,6,7,8,9,10};

int search(int  x)
{
    int i=1;
    for (; i < 10; ++i) {
        if (a[i]>x) return 0-i;
        else if(a[i]==x) return i;
    }
}

signed main() {
    cout<<search(5)<<endl;
    return 0;
}