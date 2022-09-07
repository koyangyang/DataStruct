#include "iostream"
#include"LinkList.h"
using namespace std;

int main()
{
	LinkList l;
	int a[]={1,2,3,4,5,6,1};
	InitLinkList(l);
	for(int i=0;i<7;i++){
		RearInsert(l,a[i]);
	}
	PrintLinkList(l);
	return 0;
}
