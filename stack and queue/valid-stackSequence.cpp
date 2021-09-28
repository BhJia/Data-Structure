#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/* 给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，
只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，
返回 true；否则，返回 false */
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    //把pushed的元素不断入栈，如果遇到栈顶元素就是即将出栈的元素(popped的首元素)，立即出栈
    //操作完成后如果栈中还有元素说明该元素无法pop，则返回false
    stack<int> s;
    int index = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
        s.push(pushed[i]);
        while (!s.empty() && s.top() == popped[index])
        {
            s.pop();
            index++;
        }
    }
    return s.empty();
}

void inputArr(vector<int> &arr)
{
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
    }
}