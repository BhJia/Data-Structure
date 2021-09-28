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
// 二叉分裂树最大乘积
// BFS不断更新最大值即可(这个题力扣上面超出int范围一直报错，改成Long后又是经典超时)
int mod = pow(10, 9) + 7;
template <class T>
long sum(TreeNode<T> *root)
{
    if (!root)
        return 0;
    return (long)root->val + sum(root->left) + sum(root->right);
}
template <class T>
int maxProduct(TreeNode<T> *root)
{
    long res = 0;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (t != root)
            res = max(res, sum(t) * (sum(root) - sum(t)));
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    return (int)(res % mod);
}

// 这是别人的代码
vector<long> sums;
template <class T>
int maxProduct1(TreeNode<T> *root)
{
    postOrder(root);
    long res = 0;
    for (int i = 0; i < sums.size() - 1; ++i)
    {
        res = max(res, sums[i] * (sums.back() - sums[i]));
    }
    return (int)(res % mod);
}

// 后序遍历记录每个结点的和(根节点在数组最后)
template <class T>
long postOrder(TreeNode<T> *root)
{
    if (!root)
        return 0;
    long res = root->val + postOrder(root->left) + postOrder(root->right);
    sums.push_back(res);
    return res;
}