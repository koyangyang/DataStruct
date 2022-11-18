#include <iostream>
using namespace std;
void HelanFlag(int low,int high)
{
    int mid=low;
    int a[]={0,1,2,0,1,2};
    while(low<=high)
    {
        if(a[mid]==0)//如果是0则在前部分
            swap(a[mid++],a[low++]);
        else if(a[mid]==2)//如果是2则继续前进
            mid++;
        else //如果是1则在中部分，进行交换
            swap(a[high--],a[mid]);
    }
}
int main() {
    int n=5;
    //int a[]={0,1,2,0,1,2};
    HelanFlag(1,n);
//    for(int i=1;i<=n;i++)
//        cout<<a[i]<<" ";
    return 0;
}