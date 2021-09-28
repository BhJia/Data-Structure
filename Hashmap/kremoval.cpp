#include <iostream>
#include <map>,
#include<queue>
#include <vector>
using namespace std;
//不同整数的最少种数：删除给定数组k个元素,使剩余整数种类数目最少
//方法：哈希表+优先队列(原本用哈希表+数组+排序超时)
// 思路：用哈希表统计整数出现次数,将次数升序加入优先队列,优先删除次数少的
int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    int res;
    map<int, int> m;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        q.push(it->second);
    }
    while (!q.empty())
    {
        k -= q.top();
        q.pop();
        if (k <= 0)
            return k == 0 ? q.size() : q.size() + 1; //如果k=0说明刚好删完,剩下的种数就是答案;如果k<0说明删多了要+1
    }
    return 0;
}