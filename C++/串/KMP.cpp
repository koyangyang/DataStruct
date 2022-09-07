#include<iostream>
using namespace std;
class solution{
    int *next;
    string a,b;
public:
    solution(string a,string b)
    {
        int len1,len2;
        this->a=a;
        this->b=b;
        len1=a.size();
        len2=b.size();
        next=new int[len2];
    }
    void get_next()
    {
        int i=0;
        int j=-1;
        next[i]=j;
        while(i<b.size())
        {
            if(j==-1||b[i]==b[j])
            {
                ++i;++j;
                next[i]=j;
            }
            else
                j=next[j];
        }
        for(int i=0;i<b.size();i++)
        {
            int temp=next[i]+1;
            cout<<temp;
            if(i<b.size()-1)
                cout<<" ";
        }
        cout<<endl;
    }
    void kmp()
    {
        int i=0;int j=0;
        while(i<a.size())
        {
            if(j==-1||a[i]==b[j])
            {
                ++i;++j;
            }
            else
                j=next[j];
            if(j==b.size())
            {
                cout<<i-j+1<<endl;
                return ;
            }
        }
        cout<<0<<endl;
        return ;
    }
};
int main()
{
    int i=0;
    string a,b;
    while(i<3)
    {
        cin>>a>>b;
        solution p(a,b);
        p.get_next();
        p.kmp();
        i++;
    }
    return 1;
}