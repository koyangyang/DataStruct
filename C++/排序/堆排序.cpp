//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//调整堆
void HeapAdjust(int a[], int k, int n)
{
    a[0] = a[k]; //将a[0]暂存为子树根节点
    for (int i = 2 * k; i <= n; i *= 2)
    {
        if (i < n && a[i] < a[i + 1]) //将i指向左右子树中最大的
            i++;
        if (a[0] >= a[i])
            break;
        else
        {
            a[k] = a[i]; //将子树中最大节点上浮
            k = i;       //检查根节点是否需要继续下沉
        }
    }
    a[k] = a[0]; //将根节点放置对应位置
}

//建立大根堆
void buildMaxHeap(int a[], int n)
{
    for (int i = n / 2; i > 0; --i)
        HeapAdjust(a, i, n);
}

//堆排序算法
void HeapSort(int a[], int n)
{
    buildMaxHeap(a, n);
    for (int i = n; i > 1; --i)
    {
        swap(a[i], a[1]);
        HeapAdjust(a, 1, i - 1);
    }
}

signed main()
{
    int n;
    cin >> n;
    int a[100010];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    HeapSort(a, n);
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}