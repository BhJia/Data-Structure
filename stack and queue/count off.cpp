#include <iostream>
#include <queue>
using namespace std;

void f(int n, int m)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int front;
    while (n > 0)
    {
        int j = 1;
        while (j < m)
        {
            front = q.front();
            q.pop();
            q.push(front);
            j++;
        }
        cout << q.front() << " ";
        q.pop();
        n--;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    f(n, m);
    return 0;
}