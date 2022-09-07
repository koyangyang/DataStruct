//总共要head(即第一个节点前面)，p(当前节点)，r(当前节点的下一节点，因为当前要接到头后)，rear(第一个节点，作为最后连接下一段)
//利用头插法把范围内进行反转，注意要保存好第一个节点在反转完成后接到之后的节点。
#include<bits/stdc++.h>
using namespace std;
struct node{
    node *next;
    int data;
    node(int a)
    {
        data=a;
        next=NULL;
    }
    node(): next(NULL) {}
};

class linklist{
    node *head;
    node *rear;
    int len;
    int start;
    int end;
public:
    linklist(int n,int a,int b)
    {
        head=new node;
        rear=head;
        len=n;
        start=a;
        end=b;
        for(int i=0;i<len;i++)
        {
            int temp;
            cin>>temp;
            insert(temp);
        }
    }
    void insert(int item)
    {
        node *s=new node(item);
        rear->next=s;
        rear=s;
    }
    void my_reverse()
    {
        node *p,*q,*r;
        p=head;
        int i=0;
        while(i<start-1)
        {
            p=p->next;
            i++;
        }
        q=p;
        p=p->next;
        q->next=NULL;
        rear=p;
        while(i<end)
        {
            r=p->next;
            p->next=q->next;
            q->next=p;
            p=r;
            i++;
        }
        rear->next=r;
    }
    void print()
    {
        node *p=head->next;
        while(p)
        {
            cout<<p->data;
            if(p->next!=NULL)
                cout<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main()
{
    int len,start,end;

    while(scanf("%d %d %d",&len,&start,&end)!=EOF)
    {
        linklist p(len,start,end);
        p.my_reverse();
        p.print();
    }
    return 1;
}