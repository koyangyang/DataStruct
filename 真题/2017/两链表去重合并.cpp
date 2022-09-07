struct node{
    node *next;
    int val;
};

void Union(node *L1,node *L2)
{
    node *p=L2->next;
    while(p)
    {
        node *q=L1->next;
        bool flag=0;
        while(q)
        {
            if(q->val==p->val) {
                flag=1;
                break;
            }
            q=q->next;
        }
        if(!flag)//若不在L1中，则加入L1
        {
            q=p;
            p=p->next;
            q->next=L1->next;//头插法
            L1->next=q;
        } else{
            p=p->next;
        }
    }
}