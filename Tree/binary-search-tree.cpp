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

template <class T>
void inorder(TreeNode<T> *&root, vector<T> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

//二叉搜索树的判别方法：判断中序遍历序列是否严格递增//
template <class T>
bool isValidBST(TreeNode<T> *&root)
{
    if (!root)
        return true;
    vector<T> res;
    inorder(root, res);
    for (int i = 1; i < res.size(); i++)
        if (res[i] <= res[i - 1])
            return false;
    return true;
}

template <class T>
TreeNode<T> *Insert(T target, TreeNode<T> *&root)
{
    if (!root)
        return new TreeNode<T>(target);
    else if (target < root->val)
        root->left = Insert(target, root->left);
    else
        root->right = Insert(target, root->right);
    return root;
}

template <class T>
TreeNode<T> *FindNode(T target, TreeNode<T> *&root)
{
    if (!root || root->val == target)
        return root;
    else if (target < root->val)
        return FindNode(target, root->left);
    else if (target > root->val)
        return FindNode(target, root->right);
    else
        return nullptr;
}

// 查找删除结点
// 核心:若待删除结点左右子树均不为空,把该节点左子树接到右子树最左的节点上并返回右子树
template <class T>
TreeNode<T> remove(TreeNode<T> *root, T key)
{
    if (!root)
        return nullptr;
    if (key > root->val)
        root->right = remove(root->right, key); // 去右子树删除
    else if (key < root->val)
        root->left = remove(root->left, key); // 去左子树删除
    else                                      // 当前节点就是要删除的节点
    {
        if (!root->left)
            return root->right; // 情况1，欲删除节点无左子
        if (!root->right)
            return root->left;           // 情况2，欲删除节点无右子
        TreeNode<T> *node = root->right; // 情况3，欲删除节点左右子都有
        while (node->left)               // 寻找欲删除节点右子树的最左节点
            node = node->left;
        node->left = root->left; // 将欲删除节点的左子树成为其右子树的最左节点的左子树
        root = root->right;      // 欲删除节点的右子顶替其位置，节点被删除
    }
    return root;
}

template <class T>
TreeNode<T> *dfs(vector<T> &nums, int left, int right)
{
    //给定排序数组创建二叉搜索树:分治法经典题目,套用标准模板
    if (left > right)  //结束条件
        return nullptr;
    int mid = (left + right) / 2;
    TreeNode<T> *root = new TreeNode<T>(nums[mid]);
    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);
    return root;
}

template <class T>
TreeNode<T> *sortedArrayToBST(vector<T> &nums)
{
    TreeNode<T> *root = dfs(nums, 0, nums.size() - 1);
    return root;
}

// 前序遍历创建二叉搜索树：给定前序遍历数组创建二叉搜索树
// 思路：根节点一定是首元素,且先序序列应该是形如根+左子树先序+右子树先序 的结构，
// 故可以使用lower_bound找到左右子树在当前先序序列中的划分点，递归处理左右子树
// STL语法补充：lower_bound(起始迭代器,终止迭代器,给定元素):找到容器中不小于给定元素的第一个元素
template <class T>
TreeNode<T> *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.empty())
        return nullptr;
    TreeNode<T> *root = new TreeNode(preorder[0]);
    auto it = lower_bound(preorder.begin() + 1, preorder.end(), preorder[0]);
    auto left = vector<int>(preorder.begin() + 1, it), right = vector<int>(it, preorder.end());
    root->left = bstFromPreorder(left);
    root->right = bstFromPreorder(right);
    return root;
}

template <class T>
T kthLargest(TreeNode<T> *root, int k)
{
    //直接返回中序遍历数组逆序的第k个元素
    vector<T> res;
    inorder(root, res);
    reverse(res.begin(), res.end());
    return res[k - 1];
}


// 二叉搜索树指定节点中序遍历后继
template <class T>
TreeNode<T> *inorderSuccessor(TreeNode<T> *root, TreeNode<T> *p)
{
    if (!root || !p)  //如果根节点或者指定节点为空直接返回空
        return NULL;
    if (p->val >= root->val) //如果p的值不小于根节点，则后继必然在右子树
        return inorderSuccessor(root->right, p);
    //如果p的值小于根节点,那么后继节点不在左子树就是根节点
    return inorderSuccessor(root->left, p) ? inorderSuccessor(root->left, p) : root;
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

/* 
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树种数
计dp[i]为i个节点构成的二叉搜索树个数,f(j)为以第j个节点作为根节点的二叉搜索树的个数
由于每个结点都有可能作为根节点,故dp[i]=f(1)+f(2)+...+f(i);
而以第j个节点作为根节点的树个数等于左子树与右子树个数的乘积,即f(j)=dp[j-1]*dp[i-j];
将f(j)带入原式可得转移方程(卡特兰数递推公式)：dp[i]=Σ f(j) (1<=j<=i) = Σ dp[j-1]*dp[n-j](1<=i<=n,1<=j<=i);
 */
int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j]; //注意是求和所以是+
    return dp[n];
}

int main()
{
    
    return 0;
}