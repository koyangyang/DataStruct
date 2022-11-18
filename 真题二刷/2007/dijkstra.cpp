#include "iostream"
#include "vector"
using namespace std;
int M[10][10];
vector<int> dis();

void dijstra(int n)
{
    for (int i = 0; i < n; i++)
        cout << dis[i] << " ";
}

int main()
{
    dijstra(10);
    return 0;
}