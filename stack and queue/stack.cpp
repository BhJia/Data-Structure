#include <iostream>
using namespace std;
const int maxstack = 10;
//构造数组类栈(c++可以直接用STL中的stack容器实现栈，此处是用数组类实现栈的底层原理)//
/*
    注意：count存储的永远是栈顶下一个空的位置，因此MyStack[count]是没有元素的
*/
template <class T>
class MyStack
{
public:
    MyStack(); 
    bool empty() const;
    void push(T &x);
    void pop();
    T Top();

private:
    int count;
    T stack[maxstack];
};

template <class T>
MyStack<T>::MyStack()
{
    count = 0;
}

template <class T>
bool MyStack<T>::empty() const //格式： 模板  函数类型 类名<T>::函数名()//
{
    return count == 0;
}

template <class T>
void MyStack<T>::push(T &x)
{
    if (count >= maxstack)
        cout << "The stack is full!" << endl;
    else
        stack[count++] = x;
}

template <class T>
void MyStack<T>::pop()
{
    if (count == 0)
        cout << "The stack is empty!" << endl;
    else
        count--;
}

template <class T>
T MyStack<T>::Top()
{
    if (count == 0)
        return -1;
    else
        return stack[count - 1];
}

//模拟入栈出栈过程(数组反转)//
void reverseStack()
{
    MyStack<int> s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    while (!s.empty())
    {
        cout << s.Top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    reverseStack();
    system("pause");
    return 0;
}
