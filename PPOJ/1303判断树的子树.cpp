#include <bits/stdc++.h>
using namespace std;
//只要是子树，那么一定能在主树的先序序列中找到子树的序列，那么问题就转化成KMP了吖
//gets可以读取整行字符串
const int N = 105;
int Next[N];
void getNext(char s[]) {
	Next[0] = -1;
	int i = 0, j = -1, n = strlen(s);
	while (i < n)
	{
		if (j == -1 || s[i] == s[j])Next[++i] = ++j;
		else j = Next[j];
	}
}
bool KMP(char father[], char son[]) {
	getNext(son);
	int i = 0, j = 0;
	int n = strlen(father), m = strlen(son);
	while (i<n&&j<m)
	{
		if (j == -1 || father[i] == son[j])i++, j++;
		else j = Next[j];
	}
	if (j == m)return true;
	else return false;
}
char father[N], son[N];
int main() {
	gets(father), gets(son);
	if (KMP(father, son))printf("yes");
	else printf("no");
	return 0;
}
