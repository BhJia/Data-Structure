#include <iostream>
#include <stack>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    /* 
    详细分析题目思路: 用栈存储温度下标，
    栈不为空的时候，将下一个入栈下标对应的温度与栈顶下标对应的温度对比
    如果小就入栈，这样就构造了一个递减栈；
    如果大，就意味着即将入栈的下标对应温度是第一个比栈顶下标对应温度高的值，
    此时将两个下标的差值放入res数组中作为结果，然后栈顶下标出栈，继续比较
    这个入栈下标与新的栈顶元素对应温度，重复上述步骤直到温度比栈顶小了；
    注意：此类题型栈中一般存储的是下标而非值！
    */
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> s;
    for (int i = 0; i < T.size(); i++)
    {
        //注意：此处必须用while而不是if,因为if只能比较一次，而while才是不断比较直到温度比栈顶小
        while (!s.empty() && T[i] > T[s.top()])
        {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
}

void inputArr(vector<int> &arr)
{
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
    }
}

void Print1(vector<int> &arr)
{
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " " << endl;
    }
}

int main()
{
    vector<int> res,arr;
    inputArr(arr);
    res = dailyTemperatures(arr);
    Print1(res);
    return 0;
}