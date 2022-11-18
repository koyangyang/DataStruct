#include "iostream"
using namespace std;
int *root = new int[100];
int FindRoot(int x)
{
	while (root[x] != x)
		x = root[x];
	return x;
}
void Union(int x, int y)
{
	root[y] = x;
}
void init(int n)
{
	for (int i = 0; i <= n; i++)
		root[i] = i;
}
int main()
{
	init(10);
	Union(1,2);
	Union(1,3);
	Union(2,3);
	Union(3,4);
	cout<<FindRoot(1)<<" "<<FindRoot(2)<<" "<<FindRoot(3)<<" "<<FindRoot(4)<<endl;
	return 0;
}
