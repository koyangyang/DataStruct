#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void computer(int m)
{
    for(int i=0;i<=m/3;i++)
        for (int j = 0; j <= (m-i*3)/2; j ++ )
            //if((m-3*i-2*j)>=0)
            cout << i<<" "<<j<<" "<<(m-3*i-2*j)*3<<endl;
}

int main()
{
    int m;
    cin>>m;
    computer(m);
    return 0;
}