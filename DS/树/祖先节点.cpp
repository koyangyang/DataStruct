#include "iostream"
#include"BST.h"
#include"vector"
using namespace std;
vector<Node*> path;
bool flag=true;
void PreOder(Node *T,int x)
{
	if(T&&flag)
	{
		if(T->data==x)
		{
			flag=false;
			for(int i=0;i<path.size();i++){
				cout<<path[i]->data<<" ";
			}
		}
		else
			path.push_back(T);
		PreOder(T->lson,x);
		PreOder(T->rson,x);
	}
}

int main()
{
	Node *T;
	CreateBST(T,example,num);
	InOrder(T);
	puts("");
	PreOder(T,40);
	return 0;
}
