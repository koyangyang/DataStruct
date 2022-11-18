#include "iostream"
using namespace std;

void HeapAdject(int a[],int n,int k)
{
    a[0] = a[k];
    for (int i = k * 2; i <= n;i*=2)
    {
        if(a[i]<a[i+1])
            i++;
        if(a[0]<a[i])
        {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}

void init(int a[],int n)
{
    for (int i = n / 2; i >= 1;i--)
    {
        HeapAdject(a, n, i);
    }
}

void BuildMaxHeap(int a[],int n)
{
    for (int i = 0; i < n;i++)
    {
        swap(a[1], a[n - i]);
        HeapAdject(a, n, 1);
    }
}

int main()
{

}