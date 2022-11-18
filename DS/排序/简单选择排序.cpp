#include "iostream"
using namespace std;
int a[100];
void SelectSort(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int min=i;
        for(int j=i+1;j<=n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i) swap(a[min],a[i]);
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    SelectSort(a,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}