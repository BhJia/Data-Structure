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
void createTree(TreeNode<T> *&root)
{
    T x;
    cin >> x;
    if (x == "#")
        root = nullptr;
    else
    {
        root = new TreeNode<T>(x);
        createTree(root->right);
        createTree(root->left);
    }
}

template <class T>
void createTree1(TreeNode<T> *&root, string &s, int &i)
{
    if (s[i] == '#')
        root = nullptr;
    else
    {
        string x(1, s[i]);
        root = new TreeNode<T>(x);
        createTree1(root->left, s, ++i);
        createTree1(root->right, s, ++i);
    }
}

template <class T>
void createByLevelorder(TreeNode<T> *&root, vector<T> &arr)
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
void createByLevelorder1(TreeNode<T> *&root, string &s)
{
    queue<TreeNode<T> *> q;
    if (s.size() == 0)
    {
        root = nullptr;
        return;
    }
    string y(1, s[0]);
    root = new TreeNode<T>(y);
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        if (i < s.size() && s[i] != '#')
        {
            string x(1, s[i]);
            t->left = new TreeNode<T>(x);
            q.push(t->left);
        }
        else
        {
            t->left = nullptr;
        }
        i++;
        if (i < s.size() && s[i] != '#')
        {
            string x(1, s[i]);
            t->right = new TreeNode<T>(x);
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
void preorder(TreeNode<T> *&root, vector<T> &res)
{
    if (!root)
        return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

bool flag = false;
template <class T>
void preordertraversal(TreeNode<T> *&root)
{
    if (!root)
        return;
    if (!flag)
    {
        cout << root->val;
        flag = true;
    }
    else
        cout << " " << root->val;
    preordertraversal(root->left);
    preordertraversal(root->right);
}

template <class T>
void inordertraversal(TreeNode<T> *&root)
{
    if (!root)
        return;
    inordertraversal(root->left);
    cout << root->val << " ";
    inordertraversal(root->right);
}

template <class T>
void postordertraversal(TreeNode<T> *&root)
{
    if (root)
        return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->val << " ";
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
        if (!flag)
        {
            cout << t->val;
            flag = true;
        }
        else
            cout << " " << t->val;
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

template <class T>
int height(TreeNode<T> *&root)
{
    if (!root)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}

template <class T>
int minDepth(TreeNode<T> *root)
{
    //树的最小深度:指根节点到最近的叶节点路径上的节点个数
    if (!root) //根节点为空//
        return 0;
    //根节点左右子树有一个为空//
    if (!root->left)
        return minDepth(root->right) + 1;
    if (!root->right)
        return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

//树的翻转:把左子树翻转后替换右子树,把右子树翻转替换左子树
template <class T>
TreeNode<T> *invertTree(TreeNode<T> *&root)
{

    if (!root)
        return nullptr;
    TreeNode<T> *left = invertTree(root->left);
    TreeNode<T> *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// 翻转后等价：判断一棵树是否可以通过翻转某些节点得到第二棵树
// 对称性递归经典问题：如果节点值不同,肯定不能翻转得到,如果相同,判断LL与RR/LR与RL是否可以通过翻转得到
template <class T>
bool flipEquiv(TreeNode<T> *root1, TreeNode<T> *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}

//合并二叉树(最好设置为int型树)：先考虑四种特殊情况
template <class T>
TreeNode<T> *mergeTrees(TreeNode<T> *root1, TreeNode<T> *root2)
{

    if (!root1 && !root2)
        return nullptr;
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);    //递归合并左子树
    root1->right = mergeTrees(root1->right, root2->right); //递归合并右子树
    return root1;
}

// 对称二叉树
template <class T>
bool isSymmetric(TreeNode<T> *&root)
{
    return isMirror(root, root);
}

template <class T>
bool isMirror(TreeNode<T> *&p, TreeNode<T> *&q)
{
    //递归实现：比较左右子树是否对称，就是比较左子树的左子树和右子树的右子树是否对称，以及
    //左子树的右子树和右子树的左子树是否对称，从而实现递归(把原问题细化为子问题)
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return (p->val == q->val) && (isMirror(p->left, q->right)) && (isMirror(p->right, q->left));
}

//单值二叉树：所有节点的值相同
template <class T>
bool isUnivalTree(TreeNode<T> *root)
{
    // 思路：现在根节点进行模拟,然后在左右子树分别递归
    if (!root) //根节点为空
        return true;
    if ((root->left && root->left->val != root->val) || (root->right && root->right->val != root->val))
        return false; //根节点不等于左节点或根节点不等于右节点
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

// 删除给定值的叶子结点：给定一个值，删除树中所有值为给定值的叶子结点
// 思路：简单的对称性递归,注意判断是否是待删除的叶节点要放在递归语句后面，不然会出现空节点
template <class T>
TreeNode<T> *removeLeafNodes(TreeNode<T> *root, int target)
{
    if (!root)
        return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (!root->left && !root->right && root->val == target)
        root = nullptr;
    return root;
}

template <class T>
bool isCompleteBinaryTree(TreeNode<T> *root)
{
    /* 完全二叉树定义：
    若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
    第 h 层所有的结点都连续集中在最左边
    判断完全二叉树方法：遇到空节点之后不能再次遇到非空结点
     */
    if (!root)
        return true;
    queue<TreeNode<T> *> q;
    q.push(root);
    bool hasNullptr = false; //判断是否遇到了空节点
    //层序遍历
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        q.pop();
        if (hasNullptr && t) //如果已经遇到了空节点又遇到非空结点则不是完全二叉树
            return false;
        if (!t) //遇到空节点，跳过本次循环，进入下一层循环
        {
            hasNullptr = true;
            continue;
        }
        q.push(t->left); //无论左右节点是否非空都加入队列
        q.push(t->right);
    }
    return true;
}

template <class T>
void inputArr(vector<T> &arr)
{
    T x;
    while (cin >> x)
    {
        arr.push_back(x);
        if (cin.get() == '\n')
            break;
    }
}

int main()
{
    TreeNode<string> *root;
    string s;
    cin >> s;
    int i = 0;
    createByLevelorder1(root, s);
    levelordertraversal(root);
    return 0;
}