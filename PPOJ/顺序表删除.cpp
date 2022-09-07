#include<bits/stdc++.h>
using namespace std;
const int maxlen=1000;
class seqlist{
    int data[maxlen];
    int len;
public:
    seqlist(int n)
    {
        len=n;
        for(int i=0;i<len;i++)
            cin>>data[i];
    }
    void del_x(int x)
    {
        int num,j;
        num=0;
        for(j=0;j<len;j++)
        {
            if(data[j]!=x)
            {
                data[num++]=data[j];
            }
        }
        len=num;
    }
    void print()
    {
        for(int i=0;i<len;i++)
        {
            cout<<data[i];
            if(i<len-1)
                cout<<" ";
        }
        cout<<endl;
    }
};



int main()
{
    int n,x;
    while(scanf("%d %d",&n,&x)!=EOF)
    {
        seqlist p(n);
        p.del_x(x);
        p.print();
    }
    return 0;
}