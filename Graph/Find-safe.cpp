#include<bits/stdc++.h>
using namespace std;
/* 
找到最终安全的点：给定一个图,如果一个点所有路径最终都会通往安全的点，则该点为最终安全的点
安全的点：出度为0的点
方法：反向拓扑排序
先把有向图反向,找到原图中所有出度为0的点放入队列,更新所有相邻的点的出度，再找出出度为0的点,如此往复直到所有可以拓扑排序的点都进行处理
原理：没法反向拓扑排序的点说明有环,那么就不可能走到安全点
*/
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> res;
    vector<int> outdegree(n, 0);
    vector<vector<int>> reverseG(n);
    for (int i = 0; i < n; i++)
    {
        outdegree[i] += graph[i].size();  //统计出度
        for (auto v : graph[i])  //将图反向
            reverseG[v].push_back(i);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) //把出度为0的点放入队列
        if (!outdegree[i])
            q.push(i);
    while (!q.empty())  //bfs拓扑排序
    {
        int t = q.front();
        q.pop();
        res.push_back(t);
        for (auto &v : reverseG[t])
            if (--outdegree[v] == 0)
                q.push(v);
    }
    sort(res.begin(), res.end());
    return res;
}