//
// Created by koyan on 2022/8/29.
//
#ifndef C_BST_H
#define C_BST_H
#include "iostream"
#include "stack"
using namespace std;

typedef struct BiNode{
	int data;
	struct BiNode *lson,*rson;
}BiNode,*BiTree;

int example[]={54,20,66,40,28,79,58};

int Insert_BST(BiTree &T,int x)
{
	if(T==NULL)
	{
		T=new BiNode;
		T->data=x;
		T->lson=T->rson=NULL;
		return 1;
	}
	else{
		if(T->data==x) return 0;
		else if(T->data>x) return Insert_BST(T->lson,x);
		else return Insert_BST(T->rson,x);
	}
}

void Create_BST(BiTree &T,int a[],int n)
{
	T=NULL;
	for (int i = 0; i < n; ++i)
		Insert_BST(T,a[i]);
}

void visit(BiTree T)
{
	cout<<T->data<<" ";
}

void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lson);
		visit(T);
		InOrder(T->rson);
	}
}

void PreOrder(BiTree T)
{
	if(T!=NULL)
	{
		visit(T);
		PreOrder(T->lson);
		PreOrder(T->rson);
	}
}

void PostOrder(BiTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->lson);	
		PostOrder(T->rson);
		visit(T);
	}
}

void InOrderF(BiTree T)
{
	stack<BiTree> s;
	BiTree p=T;
	while(p||!s.empty()){
		if(p)
		{
			s.push(p);
			p=p->lson;
		}
		else{
			p=s.top();s.pop();
			visit(p);
			p=p->rson;
		}
	}
}

void PreOrderF(BiTree T)
{
	stack<BiTree> s;
	BiTree p=T;
	while(p||!s.empty()){
		if(p){
			s.push(p);
			visit(p);
			p=p->lson;
		}
		else{
			p=s.top();s.pop();
			p=p->rson;
		}
	}
}

void PostOrderF(BiTree T)
{
	stack<BiTree> s;
	BiTree p=T,r=NULL;
	while(p||!s.empty()){
		if(p){
			s.push(p);
			p=p->lson;
		}
		else{
			p=s.top();
			if(p->rson&&p->rson!=r){
				p=p->rson;
			}else{
				s.pop();
				visit(p);
				r=p;
				p=NULL;
			}
		}
	}
}
#endif //C_BST_H

