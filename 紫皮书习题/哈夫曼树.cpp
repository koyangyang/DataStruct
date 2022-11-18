#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int cmp(TreeNode *x, TreeNode *y)
{
    return x->val > y->val;
}
//从大到小排序，选点直接从栈顶选

void bubbleSort(vector<TreeNode *> &nums)
{
    for (int i = nums.size() - 1; i >= 0; i++)
    {
        bool flag = false;
        if (nums[i] > nums[i - 1])
        {
            TreeNode *p = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = p;
            flag = true;
        }
        if (!flag)
            return;
    }
}

void build(vector<TreeNode *> &nums)
{
    while (nums.size() > 1)
    {
        TreeNode *p, *q;
        bubbleSort(nums);
        p = nums.back();
        nums.pop_back();
        q = nums.back();
        nums.pop_back();
        TreeNode *bt = new TreeNode(p->val + q->val);
        bt->left = p;
        bt->right = q;
        nums.push_back(bt);
    }
}
//很简单的选点过程，拿出最小两点，建立它两的祖先结点，把祖先结点入栈

int cal(TreeNode *root, int depth)
{
    if (root)
    {
        if (!root->left && !root->right)
            return depth * root->val;
        return cal(root->left, depth + 1) + cal(root->right, depth + 1);
    }
}
//遍历求ASL（当前深度*结点值）

int main()
{
    int n;
    cin >> n;
    vector<TreeNode *> nums;
    int elem;
    while (cin >> elem)
    {
        TreeNode *bt = new TreeNode(elem);
        nums.push_back(bt);
    };
    sort(nums.begin(), nums.end(), cmp); //先用sort排序一遍
    build(nums);
    TreeNode *bt = nums.back(); //栈里只有唯一结点输出即可
    cout << cal(bt, 0) << endl;
    free(bt);
    return 0;
}