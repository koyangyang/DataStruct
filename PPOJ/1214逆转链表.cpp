#include<bits/stdc++.h>
using namespace std;
#define maxlen 10000
class seqlist{
    int data[maxlen];
    int len;
    vector<int> temp;
public:
    seqlist(int n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data[i]);
            temp.push_back(data[i]);
        }
        len=n;
    }
    void my_reverse()
    {
        int i,j;
        i=0;j=len-1;
        for(;i<len/2;i++)
        {
            int temp=data[i];
            data[i]=data[j];
            data[j]=temp;
            j--;
        }
        reverse(temp.begin(),temp.end());
    }
    void print()
    {
        for(int i=0;i<len;i++)
        {
            cout<<temp[i];
            if(i<len-1)
                cout<<" ";
        }
        cout<<endl;
    }
};




int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        seqlist p(n);
        p.my_reverse();
        p.print();
    }
    return 0;
}