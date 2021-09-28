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

// 二叉树剪枝：给定一颗值为0或1的二叉树,将所有不存在1的子树去掉
// 方法1：BFS迭代+判断是否有1
template <class T>
TreeNode<T> *pruneTree(TreeNode<T> *root)
{
    if (!root || hasNoOne(root)) //注意这里要先判断整棵树是否都是没有1的
        return nullptr;
    queue<TreeNode<T>> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        if (hasNoOne(t->left)) //先判断左右子树是否有1,如果没有,直接设为空
            t->left = nullptr;
        if (hasNoOne(t->right)) 
            t->right = nullptr;
        if (t->left)           //再把非空的左右子树入队
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    return root;
}

// 判断是否有1
template <class T>
bool hasNoOne(TreeNode<T> *root)
{
    if (!root)
        return true;
    if (root->val == 1)
        return false;
    return hasNoOne(root->left) && hasNoOne(root->right);
}

// 方法2：递归+优先判断根节点
template <class T>
TreeNode<T> *pruneTree(TreeNode<T> *root)
{
    if (!root || hasNoOne(root))
        return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return root;
}

// 方法3：递归+最后判断根节点
template <class T>
TreeNode<T> *pruneTree(TreeNode<T> *root)
{
    if (!root)
        return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    // 剪枝之后如果只剩下值为0的根节点,把根节点也删掉，否则返回根节点
    return root->val==0 && !root->left && !root->right?nullptr:root; 
}


// 修剪二叉搜索树：给定二叉搜索树根节点和low,high,返回节点值在low-high之间的节点相对结构
// 思路：与二叉树剪枝相似的递归方法
template <class T>
TreeNode<T> *trimBST(TreeNode<T> *root, int low, int high)
{
    if (!root)
        return nullptr;
    if (root->val > high) //如果根节点值超过上界,那么把根节点和右子树直接删掉,返回剪枝后的左子树
        return trimBST(root->left, low, high);
    if (root->val < low)
        return trimBST(root->right, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}