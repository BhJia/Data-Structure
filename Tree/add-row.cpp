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

//在二叉树中增加一行
// 思路：DFS
template <class T>
TreeNode<T> *addOneRow(TreeNode<T> *root, int v, int d)
{
    if (d == 1)  //特殊情况
    {
        TreeNode<T> *r = new TreeNode<T>(v);
        r->left = root;
        return r;
    }
    insert(root, v, 1, d);
    return root;
}

// 这里DFS难点在于要设置一个状态变量,即当前深度cur
template <class T>
void insert(TreeNode<T> *root, int v, int cur, int d)
{
    if (!root)
        return;
    if (cur == d - 1) //如果当前深度为加入行的深度的上一层
    {
        auto left = root->left, right = root->right; //存储该节点左右子树
        root->left = new TreeNode<T>(v);   //添加左节点
        root->left->left = left;          //把原来的左子树接上去
        root->right = new TreeNode<T>(v);
        root->right->right = right;
    }
    else
    {
        insert(root->left, v, cur + 1, d);  //往下一层递归
        insert(root->right, v, cur + 1, d);
    }
}