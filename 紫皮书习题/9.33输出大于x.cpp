
BiTree DeleteMoreX(BiTree &T, int x)
{
    if (T)
    {
        if (T->key >= x)
            return DeleteMoreX(T->lchild, x);
        T->lchild = DeleteMoreX(T->lchild, x);
        T->rchild = DeleteMoreX(T->rchild, x);
        return T;
    }
    return NULL;
}