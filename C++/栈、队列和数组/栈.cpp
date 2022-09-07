#include <iostream>
using namespace std;

#define Max_Size 50
typedef struct Stack{
    int data[Max_Size];
    int top;
}SqStack;

//栈初始化
void InitStack(SqStack &S)
{
    S.top=-1;
}

//判断栈空，栈空返回true，否则返回false
bool StackEmpty(SqStack S)
{
    if(S.top==-1)
        return true;
    else
        return false;
}

//进栈，成功返回true，失败返回false
bool Push(SqStack &S,int key)
{
    if(S.top==Max_Size-1)//栈满
        return false;
    S.data[++S.top]=key;
    return true;
}

//弹出栈顶元素
bool Pop(SqStack &S,int &key)
{
    if(StackEmpty(S))//判断栈是否为空
        return false;
    key=S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,int &key)
{
    if(StackEmpty(S))//判断栈空
        return false;
    key=S.data[S.top];
    return true;
}

int main()
{
    SqStack st;
    int t;
    InitStack(st);
    for (int i = 0; i < 10; i ++ )
        Push(st,i);
    if(Pop(st,t)) cout<<t<<endl;
    if(Pop(st,t)) cout<<t<<endl;
    if(Pop(st,t)) cout<<t<<endl;
    if(GetTop(st,t)) cout<<t<<endl;
    if(GetTop(st,t)) cout<<t<<endl;
    return 0;
}