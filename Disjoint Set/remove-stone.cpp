#include<bits/stdc++.h>
using namespace std;
// 移除最多同行或同列石头：给定石头坐标,如果一个石头同行同列有石头,那么可以移除,返回可以移除的最多的石头个数
// 思路：把同行或同列石头放入并查集,返回总个数减去连通分量的个数(每个集合只要留一个即可)
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
int removeStones(vector<vector<int>> &stones)
{
    init();
    int cnt = 0, n = stones.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSame(i, j))
                continue;
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                to_union(i, j);
        }
    }
    for (int i = 0; i < n; i++) //求集合个数(连通分量个数)
        if (parent[i] == i)
            cnt++;
    return stones.size() - cnt;
}