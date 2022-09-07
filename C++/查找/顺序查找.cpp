//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int a[10]={0,4,2,3,41,9,7,11,19,110};
int search(int x)
{
    a[0]=x;
    int i=9;
    while (a[i]!=x)
        i--;
    return i;
}

signed main() {
    cout <<search(110)<< endl;
    return 0;
}