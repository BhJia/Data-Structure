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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

// 判断两棵树是否相同：根节点相同且左子树相同且右子树相同
template <class T>
bool isSameTree(TreeNode<T> *p, TreeNode<T> *q)
{
    if (!p && !q)
        return true;
    return p && q && p->val == q->val && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}

//一颗树是另一颗树的子树(两棵树非空)：1、两棵树相等  2、一棵树是左子树的子树 3、一棵树是右子树的子树
template <class T>
bool isSubtree(TreeNode<T> *root1, TreeNode<T> *root2)
{
    if (!root1 || !root2)
        return false;
    if (isSameTree(root1, root2))
        return true;
    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

// 树的子结构：给定树A,B,判断B是否是A的一个子结构
// DFS递归/BFS迭代两种方法
// hasSubStructure函数是判断如果A,B根节点相同，B是不是A的子结构
template <class T>
bool hasSubStructure(TreeNode<T> *A, TreeNode<T> *B)
{
    if (!B)        //递归结束条件1：A的一个节点B的对应位置没有,可以认为是子结构
        return true;
    if (!A || A->val != B->val)  //递归结束条件2：B的一个节点A的对应位置没有/A,B对应位置节点值不同，此时必然不可能是子结构
        return false;
    return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right); //返回值：继续在对应位置递归判断
}

// BFS迭代：A的层序遍历里如果遇到和B的根节点值相同的情况，就调用hasSubStructure函数判断B是否为A的子结构
template <class T>
bool isSubStructure(TreeNode<T> *A, TreeNode<T> *B)
{
    if (!A || !B)
        return false;
    queue<TreeNode<T> *> q;
    q.push(A);
    while (!q.empty())
    {
        TreeNode<T> *t = q.front();
        if (hasSubStructure(t, B))
            return true;
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
        q.pop();
    }
    return false;
}

// DFS：简洁很多但是很难想到，想不到就用迭代
template <class T>
bool isSubStructure1(TreeNode<T> *A, TreeNode<T> *B)
{
    if (!A || !B)   //空树判断
        return false;
    // 根节点相同的话直接进入比较，根节点不相同看B是不是A的左/右子树的子结构
    return hasSubStructure(A, B) || isSubStructure1(A->left, B) || isSubStructure1(A->right, B);
}


// 二叉树中的链表：给定一个二叉树和一个链表,判断是否存在一条自上而下的路径,与链表的每个结点值吻合
// 该题与树的子结构一模一样的方法,代码完全照搬
template <class T>
bool isSubPath(ListNode *head, TreeNode<T> *root)
{
    if (!head || !root)
        return false;
    return hasPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

template <class T>
bool hasPath(ListNode *head, TreeNode<T> *node)
{
    if (!head)
        return true;
    if (!node || node->val != head->val)
        return false;
    return hasPath(head->next, node->left) || hasPath(head->next, node->right);
}
