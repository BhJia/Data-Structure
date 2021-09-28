#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 给定非负整数数组,从start下标开始,每次可以左右移动arr[i]的距离,判断能否移动到值为0的位置
//思路:bfs,队列存储下标,每次分别左右查找,存储入队列
bool canReach(vector<int> &arr, int start)
{
    if (arr[start] == 0)
        return true;
    int n = arr.size();
    queue<int> q;
    vector<int> mark(n, 0);
    q.push(start);
    mark[start] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (t + arr[t] < n && !mark[t + arr[t]])
        {
            if (arr[t + arr[t]] == 0)
                return true;
            q.push(t + arr[t]);
            mark[t + arr[t]] = 1;
        }
        if (t - arr[t] >= 0 && !mark[t - arr[t]])
        {
            if (arr[t - arr[t]] == 0)
                return true;
            q.push(t - arr[t]);
            mark[t - arr[t]] = 1;
        }
    }
    return false;
}