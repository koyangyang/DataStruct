struct TreeNode{
    TreeNode *lson,*rson;
    int val;
};

bool Same(TreeNode *T1,TreeNode *T2)
{
    if(!T1&&!T2) return true;//如果两个节点同时为空则相等
    //逻辑运算符优先级 ! > && > ||
    if(!T1&&T2||T1&&!T2||T1->val!=T2->val)
        return false;//根节点不相等
    if(!Same(T1->lson,T2->lson)) return false;//左子树不相等
    if(!Same(T1->rson,T2->rson)) return false;//右子树不相等
    return true;//完全相等
}