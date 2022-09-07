#include<bits/stdc++.h>
using namespace std;
map<char,int> mem={
        {'+',1},
        {'-',1},
        {'*',2},
        {'/',2},
        {'^',3},
};
class solution{
    string a;
    stack<char> stk;
    int len;
    string b;
public:
    solution(string s)
    {
        a=s;
        len=a.size();
    }
    void change()
    {
        string res="";
        for(auto ch:a)
        {
            if(isalpha(ch))
                res+=ch;
            else
            {
                if(ch==')')
                {
                    while(!stk.empty()&&stk.top()!='(')
                    {
                        res+=stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                else if(ch=='(')
                    stk.push(ch);
                else
                {
                    while(!stk.empty())
                    {
                        if(stk.top()!='('&&mem[ch]<=mem[stk.top()])
                        {
                            res+=stk.top();
                            stk.pop();
                        }
                        else
                            break;
                    }
                    stk.push(ch);
                }

            }
        }
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
        b=res;
        cout<<b<<endl;
    }
};
int main()
{
    int i=0;
    string a;
    cin>>a;
    solution p(a);
    p.change();
    return 1;
}