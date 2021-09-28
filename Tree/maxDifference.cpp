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
// 节点与其祖先的最大差值：找出树中所有节点与祖先最大的差值
// 思路：节点与祖先的最大差值就是节点与祖先最大值最小值差值的较大者，因此只要在DFS的同时保存最大值，最小值即可
// 因为原函数只有一个参数，所以必须要重新创建函数
int res = 0;
template <class T>
int maxAncestorDiff(TreeNode<T> *root)
{
    dfs(root, root->val, root->val);
    return res;
}

template <class T>
void dfs(TreeNode<T> *root, int minval, int maxval)
{
    if (!root)
        return;
    res = max(res, max(abs(root->val - minval), abs(root->val - maxval)));
    minval = min(root->val, minval);
    maxval = max(root->val, maxval);
    dfs(root->left, minval, maxval);
    dfs(root->right, minval, maxval);
}