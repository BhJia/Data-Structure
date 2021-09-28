#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
void preorder(TreeNode<T> *&root, vector<T> &res)
{
    if (!root)
        return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

//将二叉树按照前序遍历展开为链表(左子树设置为空,用右子树相连成链表)
template <class T>
TreeNode<T> *flatten(TreeNode<T> *&root)
{
    if (!root)
        return nullptr;
    vector<T> res;
    preorder(root, res);
    TreeNode<T> *r = root;
    for (int i = 1; i < res.size(); i++)
    {
        root->left = nullptr;
        root->right = new TreeNode<T>(res[i]);
        root = r->right;
    }
    return r;
}
