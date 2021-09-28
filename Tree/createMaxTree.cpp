#include <iostream>
#include <vector>
#include <string>
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
TreeNode<T> *constructMaximumBinaryTree(vector<int> &nums)
{
    return createTree(nums.begin(), nums.end());
}

// 创建最大二叉树:奇特的方法,用迭代器分治递归创建
template <class T>
TreeNode<T> *createTree(vector<int>::iterator left, vector<int>::iterator right)
{
    if (left == right)
        return nullptr;
    auto mid = max_element(left, right);
    TreeNode<T> *root = new TreeNode<T>(*mid);
    root->left = createTree(left, mid);
    root->right = createTree(mid + 1, right);
    return root;
}