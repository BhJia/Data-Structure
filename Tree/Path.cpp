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
/* 
二叉树路径题DFS注意点：
1、如果是找路径和等于给定target的路径的，那么可以不用新增一个临时变量sum来判断当前路径和，只需要用target减去节点值，
然后判断target==0即可

2、是否要回溯：二叉树的问题大部分是不需要回溯的，原因如下：
  二叉树的递归部分：dfs(root->left),dfs(root->right)已经把可能的路径穷尽了,因此到任意叶节点的路径只可能有一条，
  绝对不可能出现另外的路径也到这个满足条件的叶节点的;
  而对比迷宫问题的DFS,for循环向四个方向查找每次只能朝向一个方向，并没有穷尽路径，因此某一个满足条件的点可能是有多条路径到该点的
  并且mark数组标记已经走过的路径是会受到另外路径影响的，这时候必须回溯

3、找到路径后是否要return: 取决于题目是否要求找到叶节点满足条件的路径,如果必须到叶节点,那么就要return;
但如果是到任意节点都可以，那么必不能return,因为这条路径下面还可能有更深的路径满足条件，还要继续递归

4、是否要双重递归(即调用根节点的dfs函数后，继续调用根左右节点的pathsum函数)：看题目要不要求从根节点开始的，还是从任意节点开始
*/

//路径之和1:判断是否存在一条从根节点到叶节点的路径所有节点值的和为target
template <class T>
bool hasPathSum(TreeNode<T> *&root, T target)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return root->val == target;
    return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
}

//路径之和2：找到所有从根节点到叶节点的路径和为target的路径
vector<vector<int>> res;
template <class T>
vector<vector<int>> pathSum(TreeNode<T> *root, int targetSum)
{
    vector<int> path;
    dfs(root, targetSum, path);
    return res;
}

template <class T>
void dfs(TreeNode<T> *root, int sum, vector<int> path)
{
    if (!root)
        return;
    sum -= root->val;
    path.push_back(root->val);
    if (!root->left && !root->right && sum == 0)
    {
        res.push_back(path);
        return;
    }
    dfs(root->left, sum, path);
    dfs(root->right, sum, path);
}

// 路径之和3：找到所有自顶向下路径和为target的路径个数
// 思路：双重递归：先遍历所有点，再以每个点为起点进行dfs
int count = 0;
template <class T>
int pathSum1(TreeNode<T> *root, int targetSum)
{
    if (!root)
        return 0;
    dfs1(root, targetSum);            //以root为起始点查找路径
    pathSum1(root->left, targetSum);  //左子树递归
    pathSum1(root->right, targetSum); //右子树递归
    return count;
}

template <class T>
void dfs1(TreeNode<T> *root, int sum)
{
    if (!root)
        return;
    sum -= root->val;
    if (sum == 0) //注意不要return,因为以前找到路径return是因为已经到叶节点了，下面不可能有其他路径了，而这里下面可能还有更深的路径
        count++;  //如果找到了一个路径全局变量就+1
    dfs1(root->left, sum);
    dfs1(root->right, sum);
}

// 所有路径：找到根节点到叶节点的所有路径
vector<string> res;
template <class T>
vector<string> binaryTreePaths(TreeNode<T> *root)
{
    string path = "";
    dfs(root, path);
    return res;
}

template <class T>
void dfs(TreeNode<T> *root, string path)
{
    if (!root)
        return;
    path += to_string(root->val);
    if (!root->left && !root->right)
    {
        res.push_back(path);
        return;
    }
    dfs(root->left, path + "->");
    dfs(root->right, path + "->");
}

//叶节点到根节点的最小字符串路径
vector<string> path;
template <class T>
string smallestFromLeaf(TreeNode<T> *root)
{
    dfs(root, "");
    sort(path.begin(), path.end());
    return path[0];
}

template <class T>
void dfs(TreeNode<T> *root, string s)
{
    if (!root)
        return;
    s += 'a' + root->val;
    if (!root->left && !root->right)
    {
        reverse(s.begin(), s.end());
        path.push_back(s);
        return;
    }
    dfs(root->left, s);
    dfs(root->right, s);
}

/* 
分割线：下面最长路径的题目都不是一定要自顶向下的类型(即可以从任意节点到任意节点)，这一类题目的解题思路如下：
设计一个函数，求出以一个节点为根节点的左侧最长路径left和右侧最长路径right，那么经过该节点的最长路径就是left+right
接着只需要从根节点开始dfs,不断更新全局变量即可
*/

// 二叉树最大路径和：求出从任意节点到任意节点的路径和(节点值的和不是长度)的最大值
int res = INT_MIN; //注意节点值可能为负数，因此要设置为最小值
template <class T>
int maxPathSum(TreeNode<T> *root)
{
    maxPath(root);
    return res;
}

template <class T>
int maxPath(TreeNode<T> *root) //以root为路径起始点的最长路径
{
    if (!root)
        return 0;
    // left,right分别为根节点左右子树最长路径,注意：如果最长路径<0,就不要计入到总路径中，即设置为0
    int left = max(maxPath(root->left), 0), right = max(maxPath(root->right), 0);
    res = max(res, left + right + root->val);  //比较当前最大路径和 左右子树最长路径加上根节点值的较大值，更新全局变量
    return max(left + root->val, right + root->val); //返回左右子树较长的路径加上根节点值
}


// 最长同值路径：找到从任意节点到任意节点值相同的最长路径(长度而非节点和)
template <class T>
int longestUnivaluePath(TreeNode<T> *root)
{
    if (!root)
        return 0;
    longestPath(root);
    return res;
}

template <class T>
int longestPath(TreeNode<T> *root)
{
    if (!root)
        return 0;
    int left = longestPath(root->left), right = longestPath(root->right);
    // 如果左子节点和根节点同值，更新左最长路径;否则左最长路径为0
    if (root->left && root->val == root->left->val)
        left++;
    else
        left = 0;
    if (root->right && root->val == root->right->val)
        right++;
    else
        right = 0;
    res = max(res, left + right);
    return max(left, right);
}


// 二叉树最大直径：求任意两点路径长最大值
int res1 = 0;  //路径长度不可能为负数，因此初始值设置为0即可
template <class T>
int diameterOfBinaryTree(TreeNode<T> *root)
{
    maxPath(root);
    return res1;
}
template <class T>
int maxPath(TreeNode<T> *root)
{
// 这里递归结束条件要特别注意：不能是!root(而且不需要判断root为空,因为只有非空才会进入递归),因为明显这样的话范围会缩小,实际上单个节点路径长也是0
    if (!root->left && !root->right)  
        return 0;
    int left = root->left ? maxPath(root->left) + 1 : 0;  //判断左子节点是否为空，从而更新左边最长路径
    int right = root->right ? maxPath(root->right) + 1 : 0;
    res1 = max(res, left + right); //更新全局变量
    return max(left, right);  //返回左右路径较大者
}



//伪回文路径的个数：找出二叉树中根节点到叶节点的伪回文路径的个数
// 这是最初的代码：DFS暴力遍历树求出所有路径并转换为字符串,判断是否可以排列为回文串,力扣超时
vector<string> res;
template <class T>
int pseudoPalindromicPaths(TreeNode<T> *root)
{
    int cnt = 0;
    string path = "";
    dfs(root, path);
    for (string &s : res)
        if (canPermutePalindrome(s))
            cnt++;
    return cnt;
}

template <class T>
bool canPermutePalindrome(string s)
{
    map<char, int> m;
    bool flag = false;
    for (auto i : s)
        m[i]++;
    for (auto i : m)
    {
        if (flag && i.second % 2 != 0)
            return false;
        if (i.second % 2 != 0)
            flag = true;
    }
    return true;
}

template <class T>
void dfs(TreeNode<T> *root, string path)
{
    if (!root)
        return;
    path += to_string(root->val);
    if (!root->left && !root->right)
    {
        res.push_back(path);
        return;
    }
    dfs(root->left, path);
    dfs(root->right, path);
}


// 发现不用把所有的路径都求出来再判断，可以一边深搜一边判断(要回溯撤销选择),结果居然时间复杂度没什么变化!!
int res = 0;
template <class T>
int pseudoPalindromicPaths(TreeNode<T> *root)
{
    dfs(root, "");
    return res;
}

template <class T>
void dfs(TreeNode<T> *root, string s)
{
    if (!root)
        return;
    s += to_string(root->val);
    if (!root->left && !root->right)
    {
        if (canPermutePalindrome(s))
            res++;
        return;
    }
    dfs(root->left, s);
    dfs(root->right, s);
    s.pop_back();
}
