#include<bits/stdc++.h>
using namespace std;
// 概率最大的路径
// dijkstra标准模板
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    typedef pair<double, int> p;
    vector<double> dis(n, 0);
    vector<vector<p>> graph(n);
    vector<int> visited(n, 0);
    priority_queue<p> q;  //注意优先队列默认降序
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
        graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
    }
    dis[start] = 1;
    q.push({1, start});
    while (!q.empty())
    {
        auto t = q.top();
        int v = t.second, d = t.first;
        q.pop();
        if (visited[v])
            continue;
        visited[v] = 1;
        for (auto &u : graph[v])
        {
            if (dis[v] * u.first > dis[u.second])
            {
                dis[u.second] = dis[v] * u.first;
                q.push({dis[u.second], u.second});
            }
        }
    }
    return dis[end];
}