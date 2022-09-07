struct Node{
    int val;
    struct Node* next;
};

int FindMid(Node *L)
{
    Node *p=L->next,*q=L->next;
    while(q!=NULL)
    {
        p=p->next;
        q=q->next;
        if(q->next!=NULL)
            q=q->next;
    }
    return p->val;
}