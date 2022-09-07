struct TreeNode{
    TreeNode *lson,*rson;
    int val;
};

void PreOrder(TreeNode *T,int h)
{
    if(T!=NULL){
        cout<<T->val<<" "<<h<<endl;
        PreOrder(T->lson,h+1);
        PreOrder(T->rson,h+1);
    }
}