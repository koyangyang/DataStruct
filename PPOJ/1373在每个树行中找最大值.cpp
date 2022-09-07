#include "iostream"
#include"queue"
#include"BST.h"
using namespace std;

int FindMax(BiTree T)
{
	queue<BiTree> q;
	BiTree p=T,tmp;
	int res=0;
	q.push(p);
	while(!q.empty()){
		int len=q.size();
		res=0;
		for(int i=0;i<len;i++){
			tmp=q.front();
			res+=tmp->data;
			if(tmp->lson)q.push(tmp->lson);
			if(tmp->rson)q.push(tmp->rson);
			q.pop();
		}
	}
	return res;
}

int main()
{
	BiTree T;
	Create_BST(T,example,7);
	cout<<FindMax(T);
	return 0;
}
