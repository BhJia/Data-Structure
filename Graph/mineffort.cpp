#include <bits/stdc++.h>
using namespace std;
/* 
最小体力消耗路径：这是一道非常好同时难度很高的题目,题目描述如下：给定一个高度地图heights,现在要从左上角走到右下角,
求最小体力消耗路径的体力消耗值
一条路径的体力消耗值指的是这条路径相邻点高度差的最大值。(特别注意是相邻点而非任意点)

分析：把这道题抽象成一个图的模型,把每个点都看成一个顶点,按照行的顺序从1到m*n-1标记。相邻两点的边权值即为高度差。
下面用并查集kruskal的思路分析,我们将边权升序,每次取最短的边,并将边的顶点加入并查集,如果某一次操作发现左上角和右下角的
点在同一个并查集了,那么此时路径已经找到。因为是排序好的，所以相邻点高度差最大值就是最后一条边的边权,也就是体力消耗值
*/
int parent[10001];
void init()
{
    for (int i = 0; i < 10001; i++)
        parent[i] = i;
}
int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void to_union(int x1, int x2)
{
    int p1 = find(x1);
    int p2 = find(x2);
    if (p1 == p2)
        return;
    parent[p1] = p2;
}
bool isSame(int x1, int x2)
{
    return find(x1) == find(x2);
}
int minimumEffortPath(vector<vector<int>> &heights)
{
    int mincost = 0;
    init();
    vector<pair<int, pair<int, int>>> edge;
    int m = heights.size(), n = heights[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < m)
                edge.push_back({abs(heights[i + 1][j] - heights[i][j]), {i * n + j, (i + 1) * n + j}});
            if (j + 1 < n)
                edge.push_back({abs(heights[i][j + 1] - heights[i][j]), {i * n + j, i * n + j + 1}});
        }
    }
    sort(edge.begin(), edge.end(), [&](pair<int, pair<int, int>> &p, pair<int, pair<int, int>> &q)
         { return p.first < q.first; });
    for (auto &i : edge)
    {
        mincost = i.first;
        to_union(i.second.first, i.second.second);
        if (isSame(0, m * n - 1))
            break;
    }
    return mincost;
}