#include <bits/stdc++.h>
using namespace std;
// 找到图中所有从1到n-1的路径
vector<vector<int>> res;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> path;
    dfs(graph, path, 0);
    return res;
}
void dfs(vector<vector<int>> &graph, vector<int> path, int cur)
{
    path.push_back(cur);
    if (cur == graph.size() - 1)
    {
        res.push_back(path);
        return;
    }
    for (auto &v : graph[cur])
        dfs(graph, path, v);
    path.pop_back();
}