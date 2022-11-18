BTree PreCreate(string pre,string mid,int h1,int r1,int h2,int r2)
{
	if(h2>r2) return NULL;//中序序列为空则返回
	BTree root=new BNode(pre[h1],NULL,NULL);
	int i=h2;
	while(mid[i]!=root->data) i++;//找到根节点在中序遍历的位置;
	int llen=i-h2;//中序左子树长度
	int rlen=r2-i;//中序右子树长度
	root->lson = PreCreate(pre,mid,h1+1,h1+llen,h2,h2+llen-1);//根据中序遍历左序列建立左子树
	root->rson=PreCreate(pre,mid,r1-rlen+1,r1,r2-rlen+1,r2);//根据中序遍历右序列建立右子树
	return root;
}
