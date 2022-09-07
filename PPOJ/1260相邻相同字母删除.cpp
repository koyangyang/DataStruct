#include "iostream"
#include "stack"
using namespace std;

void Delete_dup(string s){
	stack<char>st;
	for(int i = 0; i < s.size(); ++i){
		if(st.empty() || s[i]!=st.top()) st.push(s[i]); //利用栈的特性，如果后来的元素不等于栈顶元素则入栈，反之出栈，这样相当于直接删除了相同的两个元素
		else if(s[i]==st.top()) st.pop();
	}
	int n=st.size(); //之后要出栈，先保存一下栈的长度
	for(int i = n-1; i > -1; --i){ //逆向保存一下栈的内容
		s[i] = st.top();
		st.pop();
	}
	for(int i = 0; i < n; ++i)
		cout<<s[i];
	cout << endl;
}

int main()
{
	
	return 0;
}
