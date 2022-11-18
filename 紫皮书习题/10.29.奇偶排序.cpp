#include "iostream"
using namespace std;

void JiouSort(int a[],int low,int high)
{
    while(low<=high)
    {
        while(low<high&&a[low]<0)
            low++;
        while(low<high&&a[high]>=0)
            high--;
        swap(a[low], a[high]);
    }
}

int main()
{
    int a[] = {1,3,-5,-6,-9,2,7};
    JiouSort(a,0, 6);
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    return 0;
}