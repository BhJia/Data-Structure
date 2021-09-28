#include<bits/stdc++.h>
using namespace std;
// 1854、人口最多的年份：给定人口出生死亡日期，找出最早的日期，生存人口数目最多
// 思路：c++ 哈希表存放年份对应生存人数，把表中元素放到数组中自定义排序
int maximumPopulation(vector<vector<int>> &logs)
{
    int res;
    map<int, int> m;
    for (auto i : logs)
        for (int j = i[0]; j < i[1]; j++)
            m[j]++;
    vector<pair<int, int>> t;
    for (auto p : m)
        t.push_back(p);
    sort(t.begin(), t.end(), [&](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second || (a.second == b.second && a.first < b.first); });
    return t[0].first;
}