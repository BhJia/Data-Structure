#include<bits/stdc++.h>
using namespace std;
// 不邻接植花：共4种花，给图上每一个点都种一种花,使得相邻点花种类不同,返回任意一种可行方案
//经典染色问题,思路：染一个点的时候，在颜色集合中把它相邻点的颜色去掉,剩下的颜色中选一种染即可
vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<vector<int>> graph(n);
    for (auto i : paths)  //无向图邻接表
    {
        graph[i[0] - 1].push_back(i[1] - 1);
        graph[i[1] - 1].push_back(i[0] - 1);
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        set<int> color{1, 2, 3, 4};
        for (auto &v : graph[i])
            color.erase(res[v]);
        res[i] = *(color.begin());
    }
    return res;
}