#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int a = -1)
    {
        data = a;
        left = right = NULL;
    }
};

class btree
{
public:
    btree() {}
    void insert(node *&root)
    {
        int val;
        cin >> val;
        if (val == -1)
            root = NULL;
        else
        {
            root = new node(val);
            insert(root->left);
            insert(root->right);
        }
    }
    void MidSort(node *b)
    {
        if (b)
        {
            MidSort(b->left);
            cout << b->data << " ";
            MidSort(b->right);
        }
    }
};
int main()
{
    int n;
    btree p;
    node *root = NULL;
    int pos = 0;
    p.insert(root);
    p.chenxu(root);
    return 1;
}