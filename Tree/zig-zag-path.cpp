#include <bits/stdc++.h>
template <class T>
struct TreeNode
{
    T val;
    TreeNode *left, *right;
    TreeNode() : left(nullptr), right(nullptr){};
    TreeNode(T &x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(T &x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};


// 二叉树中最长交错路径
// 交错路径：选择二叉树中任意节点,左右交替向下移动直到叶节点为止,这样的路径长度
// dfs递归：分别求出当前节点向左和向右的最长路径,比较更新全局变量,同时判断向左还是向右前进,返回另一边的最大值+1
int res = 0;
template <class T>
int longestZigZag(TreeNode<T> *root)
{
    dfs(root, true);
    return res;
}
template <class T>
int dfs(TreeNode<T> *root, bool isleft)
{
    if (!root)
        return 0;
    int l = dfs(root->left, true);
    int r = dfs(root->right, false);
    res = max(res, max(l, r));
    return isleft ? r + 1 : l + 1;
}