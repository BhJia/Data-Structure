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

// 祖父节点值为偶数的节点的和
// 很好地一种递归思路：先对根节点进行单独模拟，然后返回根节点的值+左右节点的函数
template <class T>
int sumEvenGrandparent(TreeNode<T> *root)
{
    if (!root)
        return 0;
    int sum = 0;
    if (root->val % 2 == 0)
    {
        if (root->left)  //左节点非空
        {
            if (root->left->left)   //左节点左节点非空
                sum += root->left->left->val;  
            if (root->left->right)
                sum += root->left->right->val;
        }
        if (root->right)
        {
            if (root->right->left)
                sum += root->right->left->val;
            if (root->right->right)
                sum += root->right->right->val;
        }
    }
    return sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
}