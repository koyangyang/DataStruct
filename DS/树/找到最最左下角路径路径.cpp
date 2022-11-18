#include "iostream"
#include"vector"
#include"BST.h"
using namespace std;
vector<Node*> path;

void INO(Node *B)
{
	if(B)
	{
		INO(B->lson);
		path.push_back(B);
		INO(B->rson);
	}
	//path.push_back(B);
}

int main()
{
	Node *B;
	CreateBST(B,example,num);
	INO(B);
	cout<<path.size()<<endl;
	for(int i=0;i<5;i++){
		cout<<path[i]->data<<" ";
	}
	
	return 0;
}
