#include <bits/stdc++.h>
using namespace std;
//连接所有点的最小费用：给定一些点,求使得任意两点之间有且仅有一条路径的最小费用
// 费用指的是两点的曼哈顿距离
// 最小生成树kruscal算法
int parent[1001];
void init()
{
    for (int i = 0; i < 1001; ++i)
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

int minCostConnectPoints(vector<vector<int>> &points)
{
    init();
    int m = points.size();
    vector<pair<int, pair<int, int>>> edge; //边集,first费用  second:两顶点
    for (int i = 0; i < m - 1; i++)         //初始化带权边集
        for (int j = i + 1; j < m; j++)
            edge.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
    sort(edge.begin(), edge.end(), [&](pair<int, pair<int, int>> &p, pair<int, pair<int, int>> &q)
         { return p.first < q.first; }); //按权重排序
    int res = 0;
    for (auto i : edge)
    {
        if (!isSame(i.second.first, i.second.second))
        {
            res += i.first;
            to_union(i.second.first, i.second.second);
        }
    }
    return res;
}