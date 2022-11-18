#include "iostream"
using namespace std;
int a[100];
void insertsort(int a[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)//从第二个元素开始遍历
    {
        if(a[i]<a[i-1])
        {
            a[0]=a[i];//哨兵元素
            for(j=i-1;a[0]<a[j];j--)
                a[j+1]=a[j];//注意
            a[j+1]=a[0];
        }
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    insertsort(a, n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}