struct BNode{
    BNode *lson,*rson;
    int val;
};

BNode *CopyBT(BNode *T)//将二叉树T复制，并返回复制后的N指针
{
    if(!T) return NULL;//如果T为空则返回空
    BNode *N=new BNode;//申请一个新节点
    N->val=T->val;//将T->val复制过来
    N->lson=CopyBT(T->lson);//复制左子树
    N->rson=CopyBT(T->rson);//复制右子树
    return N;//返回C指针
}