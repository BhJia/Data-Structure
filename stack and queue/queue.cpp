#include <iostream>
using namespace std;
const int maxqueue = 100;
template <class T>
class CirQueue
{
public:
    CirQueue();
    bool empty() const;
    bool full() const;
    void append(T &x);
    void Delete(T &x);
    int Size();
    int front;
    int rear;
    int count;
    T Queue[maxqueue];
};

template <class T>
CirQueue<T>::CirQueue()
{
    count = 0;
    front = 0;
    rear = maxqueue - 1;
}

template <class T>
bool CirQueue<T>::empty() const
{
    return count == 0;
}

template <class T>
bool CirQueue<T>::full() const
{
    return count == maxqueue;
}

template <class T>
void CirQueue<T>::append(T &x)
{
    if (count == maxqueue)
        cout << "The queue is full!" << endl;
    else
        count++;
        rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
        Queue[rear] = x;
}

template <class T>
void CirQueue<T>::Delete(T &x)
{
    if(count==0)
        cout << "The queue is empty!" << endl;
    else
        x = Queue[front];
        count--;
        front = ((front + 1) == maxqueue) ? 0 : (front + 1);
}

template <class T>
int CirQueue<T>::Size()
{
    return count;
}

int main()
{
    CirQueue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        q.append(t);
        if(q.full())
        {
            cout<<"The queue is overflow!"<<endl;
            break;
        }
    }
    while(!q.empty())
    {
        int tmp=q.rear;
        q.Delete(tmp);
        cout << tmp << " ";
    }
}