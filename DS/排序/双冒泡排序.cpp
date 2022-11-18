#include "iostream"

using namespace std;

void BubbleSort(int a[],int low ,int high) {
    bool flag = true;
    while (low < high && flag) {
        flag = false;
        for (int i = low; i < high; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        high--;
        for (int j = high; j > low; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        low++;
    }
}

int main() {
    int n = 5;
    int a[] = {0, 4, 2, 5, 8, 1};
    BubbleSort(a, 1,n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}