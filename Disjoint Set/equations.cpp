#include<bits/stdc++.h>
using namespace std;
// 等式方程满足的可能性：给定等式和不等式方程,判断是否有矛盾
// 方法：遍历等式，将等式两边放入并查集,遍历不等式,判断是否有同一个祖先
int parent[501];
void init()
{
    for (int i = 0; i < 501; i++)
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
bool equationsPossible(vector<string> &equations)
{
    init();
    for (auto s : equations)
    {
        if (s[1] == '!')
            continue;
        int x1 = s[0] - 'a', x2 = s[3] - 'a';
        if (!isSame(x1, x2))
            to_union(x1, x2);
    }
    for (auto s : equations)
    {
        if (s[1] == '=')
            continue;
        int x1 = s[0] - 'a', x2 = s[3] - 'a';
        if (isSame(x1, x2))
            return false;
    }
    return true;
}