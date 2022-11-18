#include "iostream"
using namespace std;

void double_bubble(int a[], int n)
{
    bool flag;
    for (int di = 0; di < n; di++)
    {
        flag = false;
        for (int i = 0; i < n - di - 1; i++) //初始从0遍历到倒数第二个元素
        {
            if (a[i] > a[i + 1])
            {
                flag = true;
                swap(a[i], a[i + 1]);
            }
        }
        for (int j = n - di - 1; j >= 1; j--) //初始从倒数第二个元素开始遍历
        {
            if (a[j] < a[j - 1])
            {
                flag = true;
                swap(a[j], a[j - 1]);
            }
        }
        if (flag == false)
            return;
    }
}

int main()
{
    int a[] = {54, 20, 66, 40, 28, 79, 58};
    double_bubble(a, 7);
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    return 0;
}