#include<iostream>
#include <stack>
using namespace std;
class MinStack
{
public:
    stack<int> s;
    stack<int> mins;
    MinStack(){};
    void push(int x)
    {
        s.push(x);
        if (mins.empty() || x <= mins.top())
        {
            mins.push(x);
        }
    }
    void pop()
    {
        if (s.top() == mins.top())
        {
            mins.pop();
        }
        s.pop();
    }
    int getMin()
    {
        if (mins.empty())
        {
            return NULL;
        }
        else
        {
            return mins.top();
        }
    }
};