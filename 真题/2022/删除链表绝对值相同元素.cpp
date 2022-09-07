struct ListNode{
    ListNode *next;
    int val;
};

ListNode* deleteDuplicates(ListNode *h,int m)
{
    bool *hashArr=(bool*)malloc((m+1)* sizeof(bool));
    ListNode *p=h;
    hashArr[abs(p->val)] = true;
    while(h&&h->next)
    {
        if(!hashArr[abs(h->next->val)])
        {
            hashArr[abs(h->next->val)] = true;
        }else
        {
            h->next=h->next->next;//跳过这个节点
        }
        h=h->next;//继续寻找
    }
    return p;
}