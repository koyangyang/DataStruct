#include <iostream>
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
public:
    linklist()
    {
        head=new node;
        rear=head;
        len=0;
    }
    void insert(int item)
    {
        node *s=new node(item);
        rear->next=s;
        rear=s;
        len++;
    }
    void find_mid()
    {
        node *p,*q;
        p=head;
        q=head;
        while(p!=NULL)
        {
            p=p->next;
            q=q->next;
            if(p!=NULL)
                p=p->next;
        }
        cout<<q->data<<endl;
    }
};
int main()
{
    int n;
    linklist p;
    while(scanf("%d",&n)!=EOF)
    {
        p.insert(n);
    }
    p.find_mid();
    return 1;
}