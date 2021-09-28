#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : left(nullptr), right(nullptr){};
    TreeNode(int &x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int &x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

void preorder(TreeNode *&root, vector<TreeNode *> &res) //前序遍历，把节点存到res容器中
{
    if (!root)
        return;
    res.push_back(root);
    preorder(root->left, res);
    preorder(root->right, res);
}

void init(vector<TreeNode *> &res, int a[]) //初始化二叉树并查集，将每个节点的祖先设置为自身
{
    for (int i = 0; i < res.size(); i++)
        a[res[i]->val] = res[i]->val;
}

void bfs(TreeNode *root, int a[], vector<vector<int>> &levelorder) //层序遍历二叉树，重新设置每个节点的祖先,并返回层序结果
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        while (size--)
        {
            TreeNode *t = q.front();
            q.pop();
            level.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
                a[t->left->val] = t->val;
            }
            if (t->right)
            {
                q.push(t->right);
                a[t->right->val] = t->val;
            }
        }
        levelorder.push_back(level);
    }
}

bool sameParent(int x, int y, int parent[]) //判断两个节点是不是有共同祖先
{
    return parent[x] == parent[y];
}

bool isSameLevel(int x, int y, vector<vector<int>> &levelorder) //判断值为x,y的节点是否在同一层
{
    for (auto level : levelorder)
        if (find(level.begin(), level.end(), x) != level.end() && find(level.begin(), level.end(), y) != level.end())
            return true;
    return false;
}

//判断堂兄弟结点：在同一层，且没有共同祖先的两个节点
bool isCousins(TreeNode *root, int x, int y)
{
    if (!root)
        return false;
    vector<TreeNode *> res; //存储结点
    preorder(root, res);
    vector<vector<int>> levelorder;
    int parent[10000]; //并查集
    init(res, parent);
    bfs(root, parent, levelorder);
    return isSameLevel(x, y, levelorder) && !sameParent(x, y, parent);
}
