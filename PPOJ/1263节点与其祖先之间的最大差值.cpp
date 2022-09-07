//因为后序遍历的性质是先经历过全部祖先再到对应节点，其左兄弟节点会在到达后退栈，所以用一个数组保存所有祖先，然后计算更新全局值即可。
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int a=-1)
    {
        data=a;
        left=right=NULL;
    }
};

class btree{
public:
    int res=INT_MIN;
    int height=0;
    vector<int> stk;
    btree() {}
    void insert(node *&root)
    {
        int val;
        cin>>val;
        if(val==-1)
            root=NULL;
        else
        {
            root=new node(val);
            insert(root->left);
            insert(root->right);
        }
    }
    void houxu(node *root)
    {
        if(root==NULL)
            return ;
        stk.push_back(root->data);
        houxu(root->left);
        houxu(root->right);
		cout<<root->data<<" : ";
        for(int i=0;i<stk.size();i++)
        {
            //res=max(res,abs(stk[i]-root->data));
			cout<<stk[i]<<" ";
        }
		cout<<endl;
        stk.pop_back();
    }

};
int main()
{
    int n;
    btree p;
    node *root=NULL;
    int pos=0;
    p.insert(root);
    p.houxu(root);
    cout<<p.res<<endl;
    return 1;
}
