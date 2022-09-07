//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MaxSize 100
int newlength=0;
char ans[MaxSize];
void Remove_bracket(char *s,int length)
{
    int top=-1;
    int* stack=new int(length);
    bool* flag=new bool(length);
    memset(flag,0, sizeof(bool));//初始化flag数组
    for (int i = 0; i < length; ++i) {
        if(s[i]=='(') stack[++top]=i;//左括号压入栈
        else if(top>=0&&s[stack[top]]=='(')//栈不为空且是右括号
            flag[stack[top--]]=1,flag[i]=1;//出栈，并将flag数组的左括号和右括号位置设为1
    }
    for (int i = 0; i < length; ++i) {
        if(flag[i]==1)//将合法的括号取出
            ans[newlength++]=s[i];
    }
    s[newlength]='\0';
}

int main() {
    char s[]="((())";
    Remove_bracket(s,4);
    for (int i = 0; i < 10; ++i) {
        cout<<ans[i]<<" ";
    }
    return 0;
}