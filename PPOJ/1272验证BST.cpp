#include <bits/stdc++.h>
using namespace std;

struct Bitree {
	int val;
	Bitree *left, *right;
};

Bitree* buildTree() {
	int num;
	cin>>num;
	if(num==-1) return NULL;
	else {
		Bitree* node = new Bitree;
		node->val = num;
		node->left = buildTree();
		node->right = buildTree();
		return node;
	}
}

bool isBST(Bitree* T, int& pre) {
	if (T) {
		bool left = isBST(T->left,pre);
		if (T->val<=pre) return false;
		pre = T->val;
		bool right = isBST(T->right,pre);
		return right&&left;
	}
	return true;
}

int main() {
	Bitree* root = buildTree();
	int pre = -1e9;
	if (isBST(root,pre)) cout<<"true";
	else cout<<"false";
	return 0;
}
