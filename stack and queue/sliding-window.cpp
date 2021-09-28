#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int MaxQueue(queue<int> q)
{
    int maxsum = q.front();
    while (!q.empty())
    {
        maxsum = max(maxsum, q.front());
        q.pop();
    }
    return maxsum;
}

void PrintVector(vector<int> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    int MaxSum=0;
    vector<int> res;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        q.push(nums[i]);
    }
    res.push_back(MaxQueue(q));
    for (int i = k; i < n; i++)
    {
        q.push(nums[i]);
        q.pop();
        MaxSum = MaxQueue(q);
        res.push_back(MaxSum);
    }
    return res;
}

int main()
{
    vector<int> nums;
    vector<int> res;
    int n, k, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    cin >> k;
    res = maxSlidingWindow(nums, k);
    PrintVector(res);
    return 0;
}