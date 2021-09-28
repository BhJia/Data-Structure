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
TreeNode<T> *helper(vector<T> &preorder, vector<T> &inorder, int l1, int r1, int l2, int r2)
{
    /*
        由前序遍历和中序遍历序列构造二叉树：
        方法：分治算法
        注意到前序遍历序列首元素即为根节点，因此可以在中序遍历序列中找到这个根节点元素，
        这个元素把中序遍历序列分为左右两个序列，左边即左子树，右边即右子树，而前序遍历
        序列中也可以找到这两个子树对应的两部分，分别对着两部分递归即可。
    */
    if (l1 > r1 || l2 > r2) //结束条件
        return NULL;
    int mid = l2;
    while (inorder[mid] != preorder[l1]) //在中序序列中找到前序序列的根节点
    {
        mid++;
    }
    TreeNode<T> *root = new TreeNode<T>(preorder[l1]);                           //创建根节点
    root->left = helper(preorder, inorder, l1 + 1, l1 + mid - l2, l2, mid - 1);  //对左子树递归
    root->right = helper(preorder, inorder, l1 + mid - l2 + 1, r1, mid + 1, r2); //对右子树递归
    return root;
}

template <class T>
TreeNode<T> *buildTree(vector<T> &preorder, vector<T> &inorder)
{
    TreeNode<T> *root = helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return root;
}

template <class T>
void inputArr(vector<T> &arr)
{
    T x;
    while (cin >> x)
    {
        arr.push_back(x);
    }
}

template <class T>
void levelordertraversal(TreeNode<T> *&root)
{
    if (!root)
        return;
    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->val << " ";
        if (q.front()->left)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
    cout << endl;
}

int main()
{
    TreeNode<int> *root;
    vector<int> a1, a2;
    a1 = {3, 9, 20, 15, 7};
    a2 = {9, 3, 15, 20, 7};
    root = buildTree(a1, a2);
    levelordertraversal(root);
    return 0;
}