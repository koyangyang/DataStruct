#include "iostream"
#include"queue"
#include"BST.h"
using namespace std;

int CellOrder(BiTree T)
{
	BiTree p=T,tmp;	
	int len=0,res=T->data;
	queue<BiTree> q;
	q.push(p);
	while(!q.empty()){
		len=q.size();
		res=q.front()->data;
		for(int i=0;i<len;i++){
			tmp=q.front();
			if(tmp->lson) q.push(tmp->lson);
			if(tmp->rson) q.push(tmp->rson);
			q.pop();
		}
	}
	return res;
}

int main()
{
	BiTree T;
	int a[]={54,20,66,40,79,58};
	Create_BST(T,a,6);
	cout<<CellOrder(T);
	return 0;
}
