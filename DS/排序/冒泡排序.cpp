#include "iostream"
#include <type_traits>
using namespace std;
int a[100];
void BubbleSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        bool tag=true;
        for(int j=n-i+1;j>1;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                tag=false;
            } 
        }
        if(tag) return;
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    BubbleSort(a, n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}