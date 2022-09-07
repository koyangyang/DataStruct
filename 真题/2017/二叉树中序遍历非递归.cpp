struct BNode{
    BNode *lson,*rson;
    int val;
};
void Inorder(BNode *T)
{
    stack<BNode> s;//定义栈
    BNode *p = T;//定义辅助指针
    while (p||!s.empty())//当p非空或者s非空时
    {
        if(p) {//如果p非空，先往儿子走
            s.push(p);//将根节点压入栈
            p=p->lson;//访问左孩子
        }else//当p为空说明访问了到左孩子走到头或者右孩子为空了，此时返回父节点
        {
            p=s.top();//返回栈顶父节点
            s.pop();//弹出栈中父节点
            visit(p);//访问父节点
            p=p->rson;//继续访问右子树
        }
    }
}