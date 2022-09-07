struct ListNode{
    int val;
    ListNode *next;
};
//链表递增序列
ListNode* deleteDuplicates(ListNode *head)
{
    ListNode *p=head;
    while(p&&p->next)//如果p和p的下一个元素都存在
    {
        if(p->val==p->next->val)//如果p等于p的下一个元素，直接将下一个元素抛弃
            p->next=p->next->next;
        else p=p->next;//如果不同继续向后
    }
    return head;//返回去重后指针
}