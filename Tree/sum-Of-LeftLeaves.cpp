#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
class Tree
{
public:
    TreeNode<T> *root;
    Tree() : root(nullptr){};
    void createTree(TreeNode<T> *&root);
    void bfs(TreeNode<T> *root);
    int sumOfLeftLeaves(TreeNode<T> *root);
    int sumOfLeftLeaves_by_recursive(TreeNode<T> *root);
};

template <class T>
void Tree<T>::createTree(TreeNode<T> *&root)
{
    T x;
    cin >> x;
    if (x == 0)
    {
        root = nullptr;
    }
    else
    {
        root = new TreeNode<T>(x);
        createTree(root->left);
        createTree(root->right);
    }
}

int sum = 0;
template <class T>
void Tree<T>::bfs(TreeNode<T> *root)
{
   //非递归广度遍历：在一般层序遍历的基础上加一个判断：
   //如果队首元素左子树是叶节点，那么就把值加到全局变量sum中
    if (!root)
        return;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        if (t->left)
        {
            if (!t->left->left && !t->left->right)
            {
                sum += t->left->val;
            }
            q.push(t->left);
        }
        if (t->right)
            q.push(t->right);
        q.pop();
    }
}

template <class T>
int Tree<T>::sumOfLeftLeaves(TreeNode<T> *root)
{
    bfs(root);
    return sum;
}

template <class T>
int Tree<T>::sumOfLeftLeaves_by_recursive(TreeNode<T> *root) 
{
    int sum = 0;
    if(!root)
        return 0;
    TreeNode<T> *t = root->left;
    if(t && !t->left && !t->right)
    {
        sum += t->val;
    }
    return sumOfLeftLeaves_by_recursive(root->left) + sumOfLeftLeaves_by_recursive(root->right) + sum;
}

int main()
{
    Tree<int> t;
    t.createTree(t.root);
    cout << t.sumOfLeftLeaves_by_recursive(t.root);
    return 0;
}