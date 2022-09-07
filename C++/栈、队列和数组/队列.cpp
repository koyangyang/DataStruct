#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.rear=Q.front=0;//初始队尾、队首指针
}

bool isEmpty(SqQueue Q)
{
    if(Q.rear==Q.front) return true;//队空条件
    else return false;
}

bool EnQueue(SqQueue &Q,int x)
{
    if((Q.rear+1)%MaxSize==Q.front) return false;//队满
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

int QueueSize(SqQueue Q)
{
    return (Q.rear-Q.front+MaxSize)%MaxSize;
}

bool DeQueue(SqQueue &Q,int &x)
{
    if(Q.rear==Q.front) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}


int main() {
    SqQueue q;
    InitQueue(q);
    int x;
    for (int i = 0; i < 50; ++i) {
        EnQueue(q,i);
    }
    for (int i = 0; i < 50; ++i) {
        DeQueue(q,x);
        cout<<x<<" ";
    }
    puts("");
    cout<<QueueSize(q);
    return 0;
}