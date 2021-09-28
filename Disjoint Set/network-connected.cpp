#include<bits/stdc++.h>
using namespace std;
/*
连通网络操作次数：给定n台计算机和连接情况,可以将两台计算机直接多余的网线接到另一台计算机上,返回将所有计算机连接的最小操作次数
分析：假设n台计算机构成了x个连通分量,那么这x个连通分量全部连接的网线个数就是x-1,那么我们只要求出连通分量的个数即可
方法：两个电脑相连就放入并查集,全部合并后遍历查找有多少电脑父亲就是自己的,那就意味着有多少个不同的集合以及连通分量
注意：n台电脑相连最少需要n-1条网线,如果网线数量少于n-1,那么必然不可能全部连接
*/
int parent[100001];
void init()
{
    for (int i = 0; i < 100001; ++i)
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
int makeConnected(int n, vector<vector<int>> &connections)
{
    init();
    if (connections.size() < n - 1)
        return -1;
    int cnt = 0;
    for (auto i : connections)
        to_union(i[0], i[1]);
    for (int i = 0; i < n; i++)
        if (parent[i] == i)
            cnt++;
    return cnt - 1;
}