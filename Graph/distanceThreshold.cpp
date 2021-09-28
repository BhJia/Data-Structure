#include<bits/stdc++.h>
using namespace std;
// 阈值距离内邻居最少的城市：给定带权无向图,一个城市可以到达另一个城市,表示两个城市间存在距离最大为distanceThreshold的路径
// 求所有城市中,可到达最少数量别的城市的城市
// 思路：Floyed求任意城市间距离,遍历城市求每个城市到达别城市的数量,比较求最小
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> d(n, vector<int>(n, INT_MAX / 2));
    for (auto &i : edges)
    {
        d[i[0]][i[1]] = i[2];
        d[i[1]][i[0]] = i[2];
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int mincnt = INT_MAX;
    int res;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && d[i][j] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= mincnt)
        {
            mincnt = cnt;
            res = i;
        }
    }
    return res;
}