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

// 出现次数最多的子树元素和：子树元素和指子树所有节点值的和,求出所有子树元素和中出现次数最多的节点
// 思路：递归求子树元素和+BFS遍历节点+哈希表存放子树和出现次数+自定义排序哈希表中元素
template <class T>
int sum(TreeNode<T> *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->val;
    return root->val + sum(root->left) + sum(root->right);
}

template <class T>
vector<int> findFrequentTreeSum(TreeNode<T> *root)
{
    if (!root)
        return {};
    map<int, int> m;
    vector<pair<int, int>> temp;
    vector<int> res;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        m[sum(t)]++;
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
        q.pop();
    }
    for (auto p : m)
        temp.push_back(p);
    sort(temp.begin(), temp.end(), [&](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second; });
    int maxfreq = temp[0].second;
    for (auto i : temp)
        if (i.second == maxfreq)
            res.push_back(i.first);
    return res;
}