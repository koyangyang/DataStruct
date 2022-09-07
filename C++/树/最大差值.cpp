#include "iostream"
#include "vector"
#include "BiTree.h"
using namespace std;

int res=-9990;
vector<int> v;
void nPostOrder(BiTree T)
{
    if(T!=NULL)
    {
        v.push_back(T->data);
        nPostOrder(T->lson);
        nPostOrder(T->rson);
        cout<<T->data<<" : ";
        for (int i = 0; i < v.size(); ++i) {
            res = max(res,abs(T->data-v[i]));
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.pop_back();
    }
}

int main()
{
    BiTree T;
    int str[]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Create_BST(T,str,7);
    nPostOrder(T);
    cout<<res;
}
