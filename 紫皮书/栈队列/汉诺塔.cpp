#include "iostream"
using namespace std;
void move(char x,int n,char y)
{
    cout << "move " << n << " from " << x << " to " << y << endl;
}
void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z);
    else
    {
        Hanoi(n - 1, x, z, y);
        move(x, n, z);
        Hanoi(n - 1, y, x, z);
    }
}

int main()
{

    return 0;
}