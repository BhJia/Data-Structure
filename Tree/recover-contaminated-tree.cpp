#include <bits/stdc++.h>
using namespace std;
template <class T>
struct TreeNode
{
    T val;
    TreeNode *left, *right;
    TreeNode() : left(nullptr), right(nullptr){};
    TreeNode(T &x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(T &x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

// 给定一个全是-1的树，将其还原，满足：根节点为0，左子节点为val*2+1,右子节点为val*2+2
template <class T>
void recoverTree(TreeNode<T> *root)
{
    recover(root, 0);
}
template <class T>
void recover(TreeNode<T> *root, int val)
{
    if (!root)
        return;
    root->val = val;
    recover(root->left, 2 * val + 1);
    recover(root->right, 2 * val + 2);
}