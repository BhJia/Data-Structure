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

//最近公共祖先问题
template <class T>
TreeNode<T> *lowestCommonAncestor(TreeNode<T> *root, TreeNode<T> *p, TreeNode<T> *q)
{
    //特殊情况：1、根节点为空  2、根节点就是所给结点p、q其中一个
    if (!root || p->val == root->val || q->val == root->val)
        return root;
    //分别在左右子树查找公共祖先
    TreeNode<T> *left = lowestCommonAncestor(root->left, p, q);
    TreeNode<T> *right = lowestCommonAncestor(root->right, p, q);
    //左边没有就在右边，反之亦然
    if (!left)
        return right;
    if (!right)
        return left;
    return root;
}

// 最深叶节点的最近公共祖先：找到最深叶子结点，求出最近公共祖先 
// 方法：BFS层序遍历，用LCA函数找公共祖先
template <class T>
TreeNode<T> *lcaDeepestLeaves(TreeNode<T> *root)
{
    queue<TreeNode<T> *> q;
    vector<vector<TreeNode<T> *>> res;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        vector<TreeNode<T> *> level;
        while (count--)
        {
            auto t = q.front();
            level.push_back(t);
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        res.push_back(level);
    }
    auto leaf = res.back(); //最后一层的节点(即最深的叶节点)
    if (leaf.size() == 1)//只有一个节点那就返回本身
        return leaf[0]; 
    if (leaf.size() == 2)//两个节点调用LCA函数求
        return lowestcommonancester(root, leaf[0], leaf[1]);
    //三个即以上用一个临时变量记录两个相邻节点的最近公共祖先，然后不断更新即可
    TreeNode<T> *temp = lowestcommonancester(root, leaf[0], leaf[1]);
    for (int i = 1; i < leaf.size(); i++)
        temp = lowestcommonancester(root, temp, leaf[i]);
    return temp;
}