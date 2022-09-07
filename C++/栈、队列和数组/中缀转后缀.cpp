//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MaxSize 100

int getPriority(char c)
{
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
}

void InFixToPostFix(char infix[],char postfix[],int &top2)
{
    char s1[MaxSize];int top1=-1;
    int i=0;
    while(infix[i] != '\0')
    {
        if('0'<= infix[i]&&infix[i]<='9')
        {
            postfix[++top2] = infix[i];
            ++i;
        }
        else if(infix[i] == '(')
        {
            s1[++top1] = '(';
            ++i;
        }
        else if(
                infix[i] == '+' ||
                infix[i] == '-' ||
                infix[i] == '*' ||
                infix[i] == '/')
        {
            if(top1 == -1||s1[top1]=='('||getPriority(infix[i])>getPriority(s1[top1]))
            {
                s1[++top1] = infix[i];
                i++;
            }
            else
                postfix[++top2] = s1[top1--];
        }
        else if(infix[i] == ')')
        {
            while(s1[top1]!='(')
                postfix[++top2] = s1[top1--];
            --top1;
            ++i;
        }
    }
    while(top1!=-1)
        postfix[++top2]=s1[top1--];
}

int main() {
    char s[]="5+4/3";
    char s1[100];
    int len=-1;
    InFixToPostFix(s,s1,len);
    for (int i = 0; i <= len; ++i) {
        cout<<s1[i];
    }
    return 0;
}