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

//求根节点到叶节点的数字之和：把每个路径的所有数按根节点到叶节点的顺序组成一个数,计算所有路径的数的和
// 思路：每个结点都代表一个数，这个数是父节点的值*10加上该节点的值,最后只要把所有叶节点的数加起来即可
// 广度优先搜索：层序遍历的同时在原处修改节点的值,遇到叶节点就加入答案
vector<int> res;
template <class T>
bool isLeaf(TreeNode<T> *root)
{
    return !root->left && !root->right;
}

template <class T>
void levelorder(TreeNode<T> *root)
{
    queue<TreeNode<T> *> q;
    if (!root)
        return;
    q.push(root);
    if (isLeaf(root))
        res.push_back(root->val);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        if (t->left)
        {
            t->left->val += 10 * t->val;
            if (isLeaf(t->left))
                res.push_back(t->left->val);
            q.push(t->left);
        }
        if (t->right)
        {
            t->right->val += 10 * t->val;
            if (isLeaf(t->right))
                res.push_back(t->right->val);
            q.push(t->right);
        }
    }
}


// 深度遍历
template <class T>
int dfs(TreeNode<T> *root,int temp)
{
    if(!root)    //特殊情况优先考虑
        return 0;
    int sum = temp * 10 + root->val; //更新当前节点的值
    if(isLeaf(root))  //递归结束条件
        return sum;
    return dfs(root->left, sum) + dfs(root->right, sum); //继续递归
}

template <class T>
int sumNumbers(TreeNode<T> *root)
{
    levelorder(root);
    return accumulate(res.begin(), res.end(), 0);
}