#include<bits/stdc++.h>
using namespace std;
// 冗余连接：给定无向图，删除一条边使得图变成树
// 并查集模板题,如果两条边不在一个集合，就加入一个集合;如果在一个集合,说明这就是要删除的边
int parent[1001];
void init()
{
    for (int i = 0; i < 1001; i++)
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
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    init();
    for (auto i : edges)
    {
        if (isSame(i[0], i[1]))
            return {i[0], i[1]};
        to_union(i[0], i[1]);
    }
    return {};
}