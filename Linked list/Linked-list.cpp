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

//求表长
int length(node *head)
{
    node *p = head;
    int j = 0;
    while (p)
    {
        j++;
        p = p->next;
    }
    return j;
}

// 找第K个节点
node *Findkth(int k, node *head)
{
    int i = 1;
    node *p = head;
    while (p && i < k)
    {
        p = p->next;
        i++;
    }
    return i == k ? p : nullptr;
}

//找值为K的结点
node *FindKth(int K, node *head)
{
    node *p = head;
    while (p && p->val != K)
    {
        p = p->next;
    }
    return p;
}

// 找中间结点(快慢指针法)
node *endOfFirstHalf(node *head)
{
    node *fast = head, *slow = head;
    while (fast->next && fast->next->next)//这里找的是中间偏左的节点
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// 插入节点
node *Insert(int x, int i, node *head)
{
    node *p, *q;
    q = new node(x, nullptr);
    if (i == 1)
    {
        q->next = head;
        return q;
    }
    else
    {
        p = Findkth(i - 1, head);
        q->next = p->next;
        p->next = q;
        return head;
    }
}

// 删除第i个节点
node *deleteNode(int i, node *head)
{
    node *p, *q;
    if (i == 1)
    {
        q = head;
        head = head->next;
        delete (q);
        return head;
    }
    p = Findkth(i - 1, head);
    if (!p || !p->next)
    {
        return NULL;
    }
    else
    {
        q = p->next;
        p->next = q->next;
        delete (q);
        return head;
    }
}

//删除倒数第i个节点
node *removeNthfromEnd(int i, node *head)
{
    return deleteNode(length(head) + 1 - i, head);
}

//遍历删除值为K的节点
node *DELETE(int k, node *head)
{
    node *p, *q;
    while (head && head->val == k) //如果表头就是要删的,把head右移到非删除元素
    {
        head = head->next;
    }
    if (head) //如果移动Head后链表不为空
    {
        p = head;
        q = head->next;
        while (q) //双指针同时移动直到快指针先找到要删除的节点
        {
            if (q->val == k)
            {
                p->next = q->next;
                delete (q);
                q = p->next;
            }
            else
            {
                q = q->next;
                p = p->next;
            }
        }
        return head;
    }
    else //如果移动后链表为空
    {
        return NULL;
    }
}

//链表反转
node *reverseList(node *head)
{
    node *pre = nullptr, *cur = head, *pos = nullptr; //三指针法
    while (cur) //三指针同时移动,并不断使中指针指向前指针
    {
        pos = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pos;
    }
    return pre;
}

//判断环形链表:快慢指针是否会相遇
bool hasCycle(node *head)
{
    if (!head || !head->next)
        return false;
    node *fast = head, *slow = head;
    while (1)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// 判断回文链表:把链表从中间分成两半,后面一半反转,然后前后比较
bool isPalindrome(node *head)
{
    if (!head)
        return true;
    node *firstHalfEnd = endOfFirstHalf(head); // 找到前半部分链表的尾节点
    node *secondHalfStart = reverseList(firstHalfEnd->next); //反转后半部分链表
    // 判断是否回文
    node *p1 = head,*p2 = secondHalfStart;
    while (p2)
    {
        if (p1->val != p2->val)
           return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

// 删除链表重复节点：双循环迭代
node *deleteDuplicates(node *head)
{
    if (!head || !head->next)
        return head;
    node *p = head, *q;
    while (p)
    {
        q = p;
        while (q->next)
        {
            if (q->next->val == p->val)
                q->next = q->next->next;
            else
                q = q->next;
        }
        p = p->next;
    }
    return head;
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
    node *head;
    int n;
    cin >> n;
    head = CreateCirNode(n);
    head = removeNthfromEnd(5, head);
    printNode(head);
    return 0;
}