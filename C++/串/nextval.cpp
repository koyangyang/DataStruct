//#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void get_nextval(string T,int nextval[])
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T.size())
    {
        if(j==0||T[i]==T[j])//匹配成功
        {
            ++i;++j;//后移
            if(T[i]!=T[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
}

void get_next(string T,int next[]) {
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < T.size()) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            //若pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        } else {
            //否则令j=next[j]，循环继续
            j = next[j];
        }
    }
}

int main() {
    string s="ababaa";
    int next[7]={0,1,0,0,0,0,0};
    int nextval[7]={0,0,0,0,0,0,0};
    get_next(s, next);
    get_nextval(s,nextval);
    for (int i = 1; i <= s.size(); ++i) {
        cout<<next[i];
    }
    puts("");
    for (int i = 1; i <= s.size(); ++i) {
        cout<<nextval[i];
    }
    return 0;
}