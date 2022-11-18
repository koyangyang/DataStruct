#include "iostream"
using namespace std;
int a[100];
void ShellSort(int a[],int n)
{
    int i,j;
    for(int dk=n/2;dk>=1;dk=dk/2 )
    {
        for(int i=dk+1;i<=n;i++)
        {
            if(a[i]<a[i-dk])
            {
                a[0]=a[i];
                for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
                    a[j+dk]=a[j];
                a[j+dk]=a[0];
            }
        }
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    ShellSort(a, n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}