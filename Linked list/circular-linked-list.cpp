#include <iostream>
using namespace std;
struct Node
{
    int m_value;
    struct Node *m_next;
    Node() : m_next(nullptr){};
    Node(int value, Node *next) : m_value(value), m_next(next){};
};

Node *CreateCirNode(int n);
void deleteCirNode(Node *&head, int n, int m);
void deleteNode(Node *&head, Node *p);

//创建环形链表//
Node *CreateCirNode(int n)
{
    Node *head, *last, *p;
    head = last = new Node(1, nullptr);
    for (int i = 2; i <= n; i++)
    {
        p = new Node(i, NULL);
        last->m_next = p;
        last = p;
    }
    last->m_next = head;
    return head;
}
//用环形链表的删除实现约瑟夫问题//
void deleteCirNode(Node *&head, int n, int m)
{
    Node *p = head, *q = p;
    int i, j;
    //这里是删除n-1个人
    //for (i = 1; i <= n; i++)
    for (i = 1; i < n; i++)
    {
        j = 1;
        p = q;
        while (j < m)
        {
            p = p->m_next;
            j++;
        }
        q = p->m_next;
        if (q)
        {
            deleteNode(head, p);
        }
    }
    cout << head->m_value << endl;
}
//删除链表指定节点//
void deleteNode(Node *&head, Node *p)
{
    Node *q = head;
    while (q->m_next != p)
    {
        q = q->m_next;
    }
    if (p == head)
    {
        head = head->m_next;
    }
    q->m_next = p->m_next;
    delete (p);
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node *head = CreateCirNode(n);
    deleteCirNode(head, n, m);
    return 0;
}
