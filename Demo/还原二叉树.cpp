#include "iostream"
using namespace std;

BiTree PreCreate(string pre,int h1,int l1,string post,int h2,int l2)
{
    if(h2>l2) return NULL;
    BiTree root=new BitNode;
    char croot=pre[0];
    int idx=0;
    while(croot[0]!=post[idx])
        idx++;
    int left=idx-1,right=l2-idx;
    root->lson=PreCreate(pre,1,idx,);
}

int main()
{

}