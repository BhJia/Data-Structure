#include <iostream>
#include <string>
using namespace std;
#define max 26
// 字典树是一个多叉树，每一层最多26个子树，对应26个字母//
//也可以理解成一个单叉树，每个节点由一个最大容量是26的数组构成//
struct TrieNode
{
    int num;  //num+1表示字典树的最大层数(num表示字典树存储的单词的最长长度)//
    TrieNode *next[max]; //next指针数组存储了下一层的字母,最多26个//
};

class Trie
{
public:
    TrieNode *root;
    Trie() : root(nullptr){};
    TrieNode *CreateTrie();                    //字典树的节点建立//
    void Insert(string str, TrieNode *root);   //字典树的节点插入//
    bool Search(string str, TrieNode *root);    //字典树的查找//
};

TrieNode *Trie::CreateTrie()
{
    TrieNode *p = new TrieNode;
    p->num = 0;
    for (int i = 0; i < max; i++)
    {
        p->next[i] = NULL;
    }
    return p;
}

//插入方法是按照层序遍历的方法逐一对比单词和字典树//
//如果已经有字母了，就继续下一层的插入，否则在这一层对应位置插入字母//
void Trie::Insert(string str, TrieNode *root)
{
    int len = str.size();
    TrieNode *p = root;
    TrieNode *t;
    for (int i = 0; i < len; i++)
    {
        int pos = str[i] - 'a';
        if (!p->next[pos])
        {
            p->next[pos] = CreateTrie();
            p = p->next[pos];
            p->num++;
        }
        else
        {
            p = p->next[pos];
        }
    }
}

bool Trie::Search(string str, TrieNode *root)
{
    int len = str.size();
    TrieNode *p = root;
    TrieNode *t;
    for (int i = 0; i < len; i++)
    {
        int pos = str[i] - 'a';
        if (!p->next[pos])
        {
            return false;
        }
        p = p->next[pos];
    }
    return true;
}