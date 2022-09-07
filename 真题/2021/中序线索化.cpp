struct TreeNode
{
    int val;
    int ltag,rtag;
    TreeNode *lson,*rson;
};

void visit(TreeNode* &p,TreeNode* &pre)
{
    if(p->lson==NULL)
    {
        p->lson=pre;
        p->ltag=1;
    }
    if(pre!=NULL&&pre->rson==NULL)
    {
        pre->rson=p;
        pre->rtag=1;
    }
    pre=p;
}

void InThread(TreeNode* &T,TreeNode* &pre)
{
    if(T!=NULL)
    {
        InThread(T->lson,pre);
        visit(T,pre);
        InThread(T->rson,pre);
    }
}