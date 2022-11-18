#include "bits/stdc++.h"
using namespace std;
typedef struct term
{
	int row,col;
	int data;
}Term;
typedef struct Trimat
{
	int num;
	Term table[100];
}Trimat;
void quick(Trimat &trimat,int n)
{
	Trimat ntrimat;
	ntrimat.num=trimat.num;
	int *colnum=new int[n+1],*pos=new int[n+1];
	for(int i=0;i<=n;i++){
		colnum[i]=0;
		pos[i]=0;
	}
	for(int i=1;i<=trimat.num;i++){
		colnum[trimat.table[i].col]++;
	}
	pos[0]=1;
	for(int i=1;i<=n;i++){
		pos[i]=colnum[i-1]+pos[i-1];
	}
	for(int i=1;i<=n;i++){
		cout<<pos[i]<<" "<<colnum[i]<<endl;
	}
}
int main()
{
	Trimat trimat;
	trimat.num=4;
	trimat.table[1].col=1;
	trimat.table[1].row=1;
	trimat.table[1].data=1;
	trimat.table[2].col=2;
	trimat.table[2].row=2;
	trimat.table[2].data=2;
	trimat.table[3].col=3;
	trimat.table[3].row=2;
	trimat.table[3].data=5;
	trimat.table[4].col=3;
	trimat.table[4].row=3;
	trimat.table[4].data=3;
	quick(trimat,3);
//	for(int i=1;i<=n;i++){
//		cout<<trimat.table[i].row<<" "<<trimat.table[i].col<<" "<<trimat.table[i].data<<endl;
//	}
	return 0;
}
