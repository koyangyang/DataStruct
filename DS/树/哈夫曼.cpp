#include "iostream"
#include "queue"
#include "vector"
using namespace std;
struct Node
{
	Node(int w, struct Node *l, struct Node *r) : data(w), lson(l), rson(r) {}
	int data;
	struct Node *lson, *rson;
};
struct cmp
{
	bool operator()(Node *a, Node *b)
	{
		return a->data > b->data;
	}
};
Node* create(vector<int> &A)
{
	if (A.size() < 1)
		return NULL;
	priority_queue<Node *, vector<Node *>, cmp> q;//小根堆
	for (int i = 0; i < A.size(); i++)
	{
		Node *node = new Node(A[i], NULL, NULL);
		q.push(node);
	}
	while (q.size() > 1)
	{
		Node *lson = q.top();
		q.pop();
		Node *rson = q.top();
		q.pop();
		int w = lson->data + rson->data;
		Node *parent = new Node(w, lson, rson);
		q.push(parent);
	}
	return q.top();
}
void inorder(Node *T)
{
	if (T)
	{
		inorder(T->lson);
		cout << T->data << " ";
		inorder(T->rson);
	}
}
int main()
{
	vector<int> a;
	for (int i = 1; i < 5; i++)
		a.push_back(i);
	Node *T = create(a);
	inorder(T);
}
