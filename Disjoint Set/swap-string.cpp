#include<bits/stdc++.h>
using namespace std;
// 交换字符串中元素
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
string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
{
    init();
    for (auto &i : pairs)
        to_union(i[0], i[1]);
    map<int, string> m;
    for (int i = 0; i < s.size(); i++) //用哈希表记录所有的集合：key:所有集合的根节点 value:集合的元素
        m[find(i)] += s[i];
    for (auto &p : m)
        sort(p.second.begin(), p.second.end(), greater<int>());
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = m[find(i)].back();
        m[find(i)].pop_back();
    }
    return s;
}