#include "iostream"
#include <type_traits>
using namespace std;
int a[100];
void AdjustHeap(int a[],int k,int n)
{
    a[0]=a[k];
    for(int i=2*k;i<=n;i*=2)
    {
        if(i<n&&a[i]<a[i+1])
            i++;
        if(a[0]<a[i])
        {
            a[k]=a[i];
            k=i;
        }
        else break;
    }
    a[k]=a[0];
}
void BuildHeap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        AdjustHeap(a, i, n);
}
bool judge(int a[],int n)
{
    if(n%2==0)
    {
        if(a[n/2]<a[n]) return false;
        for(int k=n/2-1;k>=1;k--)
            if(a[k]<a[k*2]||a[k]<a[2*k+1])
                return false;
    }else
    {
        for(int k=n/2;k>=1;k--)
            if(a[k]<a[k*2]||a[k]<a[2*k+1])
                return false;
    }
    return true;
}
void HeapSort(int a[],int n)
{
    BuildHeap(a, n);
    cout<<"是否是大根堆："<<judge(a,n)<<endl;
    for(int i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        AdjustHeap(a, 1, i-1);
    }
}
int main()
{
    int n=5;
    int a[]={0,4,2,5,8,1};
    HeapSort(a,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}