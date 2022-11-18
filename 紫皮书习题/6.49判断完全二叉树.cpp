#include <iostream>
#include"queue"
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

bool judge(BiTree T)
{
    queue<BiTree> q;
    BiTree p=T;
    int flag=0;
    q.push(p);
    while(!q.empty())
    {
        int len=q.size();
        for(int i=0;i<len;i++)
        {
            BiTree tmp=q.front();q.pop();
            if(tmp->lson==NULL)
            {
                if(tmp->rson) return false;
                else {
                    for(int j=i+1;j<len;j++)
                    {
                        BiTree tt=q.front();q.pop();
                        if(!tt->lson||!tt->rson) return false;
                    }
                }
            } else q.push(tmp->lson);
           if(tmp->rson==NULL)
            {
                    for(int j=i+1;j<len;j++)
                    {
                        BiTree tt=q.front();q.pop();
                        if(!tt->lson||!tt->rson) return false;
                    }
            }
            else q.push(tmp->rson);
        }
        return true;
    }}

//二叉排序树的创建，中序遍历，查找，删除
int main()
{
    BiTree T;   //树根
    KeyType str[]={54,20,66};//将要进入二叉排序树的元素值
    Creat_BST(T,str,3);
    cout<<judge(T);
    return 0;
}