#include "iostream"
#include "stack"
using namespace std;
stack<pair<int, int>> stk;

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[], int n)
{
    stk.push({0, n});
    while (!stk.empty())
    {
        int low = stk.top().first;
        int high = stk.top().second;
        stk.pop();
        int pivot = Partition(a, low, high);
        if (pivot - 1 > low)
            stk.push({low, pivot - 1});
        if (pivot + 1 < high)
            stk.push({pivot + 1, high});
    }
}

int main()
{
    int a[] = {54, 20, 66, 40, 28, 79, 58};
    QuickSort(a, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}