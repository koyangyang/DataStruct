#include <bits/stdc++.h>
using namespace std;

bool sign = false;
int i = 0;
int getNum(string &s, int &idx) {
    int result = 0;
    while(s[idx]<='9' && s[idx]>='0') {
        result = result*10 + s[idx] - '0';
        idx++;
    }
    idx--;
    if (sign) {
        sign = false;
        result = -result;
    }
    return result;
}

bool isPrior(char a, char b) {
// whether a is prior than b
    if (b=='+'||b=='-') {
        if (a=='*'||a=='/') return true;
    }
    return false;
}

bool isOpt(char c) {
    if (c=='+' || c=='-' || c=='*' || c=='/') return true;
    return false;
}

int calab(int a, int b, char c) {
    if (c=='+') return a+b;
    else if (c=='-') return a-b;
    else if (c=='*') return a*b;
    else return a/b;
}

int calculate(string s) {
    stack<int> nums;
    int len = s.length();
    int num0, num1;
    for (; i < len; i += 1) {
        if (isOpt(s[i])) {
            if (s[i]=='-') {
                sign = true;
                continue;
            } else if (s[i]=='*'||s[i]=='/') {
                char op = s[i];
                i++;
                if (s[i]=='(') {
                    i++;
                    if (sign) {
                        sign = false;
                        num1 = -(calculate(s));
                    } else num1 = calculate(s);
                } else num1 = getNum(s, i);
                num0 = nums.top();
                nums.pop();
                nums.push(calab(num0, num1, op));
            }
        } else if (s[i]=='(') {
            i++;
            if (sign) {
                sign = false;
                num0 = -(calculate(s));
            } else num0 = calculate(s);
            nums.push(num0);
        } else if (s[i]==')') break;
        else {
            num0 = getNum(s, i);
            nums.push(num0);
        }
    }
    while(nums.size()>1) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        num0 = a+b;
        nums.push(num0);
    }
    return nums.top();
}

int main() {
    string str;
    while(cin>>str) {
        i = 0;
        sign = false;
        cout<<calculate(str)<<endl;
    }

    return 0;
}