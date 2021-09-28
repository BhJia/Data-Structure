#include<bits/stdc++.h>
using namespace std;
// 最大网络秩：两点间网络秩指的是与两点各自直接相连的道路总数,连接两点的道路只被计算一次
// 思路：如果两点相连,那么秩为两点度之和-1，如果两点不连，秩为度的和;
int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<int> degree(n, 0); //记录度
    vector<vector<int>> connect(n, vector<int>(n, false)); //记录连通性
    for (auto &i : roads)
    {
        degree[i[0]]++;
        degree[i[1]]++;
        connect[i[0]][i[1]] = 1;
        connect[i[1]][i[0]] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int rank = connect[i][j] ? degree[i] + degree[j] - 1 : degree[i] + degree[j];
            res = max(res, rank);
        }
    return res;
}