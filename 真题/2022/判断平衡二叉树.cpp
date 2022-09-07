int Flag=1;
typedef struct node{
    int val;
    struct node *lson,*rson;
}node;
//二叉树高度
int Depth(node *root)
{
    if(root==NULL) return 0;
    return max(Depth(root->lson),Depth(root->rson))+1;
}
//递归判断二叉树是否高度平衡
void judge(node *root)
{
    //若节点为空或Flag已经为0直接返回
    if(!Flag||root==NULL)return;
    //若高度差大于1，则置Flag为1
    if(abs(Depth(root->lson)-Depth(root->rson))>1) Flag=0;
    judge(root->lson);
    judge(root->rson);
}
//递归判断是否为二叉排序树
bool isbst(node *root,int l,int r)
{
    if(root==NULL) return true;
    //如果当前节点的值小于等于min(l,r)或者大于等于max(l,r)则不是二叉排序树
    if(root->val<=min(l,r)||root->val>=max(l,r)) return false;
    //遍历左子树，r更新为当前值
    int okl=isbst(root->lson,l,root->val);
    //遍历右子树，l更新为当前值
    int okr=isbst(root->rson,root->val,r);
    return okl&&okr;
}
//判断树T是否为平衡二叉树
bool isval(node *T)
{
    if(isbst(T,T->lson->val,T->rson->val))
    {
        judge(T);
        if(Flag) return true;
        else return false;
    } else return false;
}