#include <iostream>
using namespace std;
struct node
{
    int val;
    struct node *next;
    node() : next(nullptr){};
    node(int value, node *next) : val(value), next(next){};
};

node *CreateCirNode(int n)
{
    node *head, *last, *p;
    int x;
    cin >> x;
    head = last = new node(x, nullptr);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = new node(x, nullptr);
        last->next = p;
        last = p;
    }
    return head;
}

/**快慢指针找链表中间结点,并将链表分割，返回后一半的头结点**/
node *cutlist(node *&head)
{
    node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/*合并两个链表为一个升序链表*/
node *mergeTwoLists(node *&l1, node *&l2)
{
    if (!l1 || !l2)
    {
        return l1 ? l1 : l2;
    }
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    l2->next = mergeTwoLists(l2->next, l1);
    return l2;
}

/*归并排序*/
node *sortList(struct node *&head)
{
    if (!head || !head->next)
    {
        return head;
    }
    node *l1 = head;
    node *l2 = cutlist(head);
    l1 = sortList(l1);
    l2 = sortList(l2);
    return mergeTwoLists(l1, l2);
}

void printNode(node *head)
{
    node *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

int main()
{
    node *head1, *head2;
    int n, m;
    cin >> n;
    head1 = CreateCirNode(n);
    cin >> m;
    head2 = CreateCirNode(m);
    node *head = mergeTwoLists(head1, head2);
    printNode(head);
    return 0;
}