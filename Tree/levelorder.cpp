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

template <class T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode(T x) : val(x), next(NULL){};
};

template <class T>
void createTree_by_levelorder(TreeNode<T> *&root, vector<T> &arr)
{
    queue<TreeNode<T> *> q;
    if (arr.empty())
    {
        root = nullptr;
        return;
    }
    root = new TreeNode<T>(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != "#")
        {
            t->left = new TreeNode<T>(arr[i]);
            q.push(t->left);
        }
        else
        {
            t->left = nullptr;
        }
        i++;
        if (i < arr.size() && arr[i] != "#")
        {
            t->right = new TreeNode<T>(arr[i]);
            q.push(t->right);
        }
        else
        {
            t->right = nullptr;
        }
        i++;
    }
}

template <class T>
void levelordertraversal(TreeNode<T> *&root)
{
    queue<TreeNode<T> *> q;
    if (!root)
        return;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        cout << t->val << " ";
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
}

//锯齿状层序遍历
template <class T>
vector<vector<T>> zigzagLevelOrder(TreeNode<T> *&root)
{
    vector<vector<int>> res;
    queue<TreeNode<T> *> q;
    if (root)
        q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size, 0);
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            level[flag ? i : size - i - 1] = root->val;
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        res.push_back(level);
        flag = !flag;
    }
    return res;
}

template <class T>
vector<vector<T>> levelOrderBottom(TreeNode<T> *&root)
{
    //自底向上的层序遍历：所有层遍历完成后将大容器反转
    vector<vector<T>> res;
    if (!root)
    {
        return res;
    }
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<T> level;
        int count = q.size();
        while (count--)
        {
            level.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(level);
    }
    reverse(res.begin(), res.end());
    return res;
}

template <class T>
vector<T> rightSideView(TreeNode<T> *&root)
{
    //树的右视图：取层序遍历每层最后一个元素
    vector<T> res;
    if (!root)
        return res;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        vector<T> level;
        while (count--)
        {
            level.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(level[level.size() - 1]);
    }
    return res;
}

//求每一层的最大元素:层序遍历后排序
template <class T>
vector<T> largestValues(TreeNode<T> *&root)
{
    vector<T> res;
    if (!root)
        return res;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<T> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode<T> *t = q.front();
            level.push_back(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            q.pop();
        }
        sort(level.begin(), level.end());
        reverse(level.begin(), level.end());
        res.push_back(level[0]);
    }
    return res;
}

//将二叉树每一层的节点构成链表(层序遍历基础)
template <class T>
vector<ListNode<T> *> createList(TreeNode<T> *tree)
{
    vector<ListNode<T> *> res;
    if (!tree)
        return res;
    queue<TreeNode<T> *> q;
    q.push(tree);
    while (!q.empty())
    {
        int size = q.size();
        //按照创建链表的方法(尾插法)创建
        ListNode<T> *head = new ListNode<T>(q.front()->val);
        ListNode<T> *p = head;
        for (int i = 0; i < size; i++)
        {
            TreeNode<T> *t = q.front();
            q.pop();
            //注意:每层最后一点q.front()是nullptr,因此要加判断
            if (i < size - 1)
            {
                p->next = new ListNode<T>(t->val);
                p = p->next;
            }
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        res.push_back(head);
    }
    return res;
}

// 奇偶树
template <class T>
bool isEvenOddTree(TreeNode<T> *root)
{
    vector<vector<int>> res;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int count = q.size();
        while (count--)
        {
            level.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(level);
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (res[i].size() == 1 && res[i][0] % 2 == 0)
                return false;
            for (int j = 0; j < res[i].size() - 1; j++)
                if (res[i][j] % 2 == 0 || res[i][j] >= res[i][j + 1])
                    return false;
            if (res[i].back() % 2 == 0)
                return false;
        }
        else
        {
            if (res[i].size() == 1 && res[i][0] % 2)
                return false;
            for (int j = 0; j < res[i].size() - 1; j++)
                if (res[i][j] % 2 || res[i][j] <= res[i][j + 1])
                    return false;
            if (res[i].back() % 2)
                return false;
        }
    }
    return true;
}