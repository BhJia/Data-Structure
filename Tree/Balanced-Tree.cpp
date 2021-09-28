#include<bits/stdc++.h>
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

template <class T>
int height(TreeNode<T> *&root)
{
    if (!root)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}

// 判断平衡二叉树：两种方法：递归/迭代
//bfs遍历二叉树判断左右子树高度差<=1
template <class T>
bool isBalanced_BFS(TreeNode<T> *&root)
{
    
    if (!root || (!root->left && !root->right))
        return true;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        if (abs(height(t->left) - height(t->right)) > 1)
            return false;
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
        q.pop();
    }
    return true;
}

//递归判断平衡二叉树:左右子树最大高度<=1且左右子树都是平衡二叉树
template <class T>
bool isBalanced(TreeNode<T> *&root)
{
    if (!root)
        return true;
    return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}