#include<bits/stdc++.h>
using namespace std;
// 节点间通路：判断节点是否连通
// 思路：BFS查找所有和start连通的点看target是否在其中
bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target)
{
    vector<vector<int>> edge(n);
    vector<int> visited(n, 0);
    for (auto i : graph)
        edge[i[0]].push_back(i[1]);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == target)
            return true;
        visited[v] = 1;
        for (auto p : edge[v])
            if (!visited[p])
                q.push(p);
    }
    return false;
}