#include<bits/stdc++.h>
using namespace std;
// 课程表4：给定课程顺序,查询课程顺序是否正确
// 方法：Floyed+传递闭包：两个点顺序正确当且仅当加了中间站仍然正确
vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<vector<bool>> d(n, vector<bool>(n, false));
    for (auto &i : prerequisites)
        d[i[0]][i[1]] = true;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] && d[k][j])
                    d[i][j] = true;
    vector<bool> res;
    for (auto &q : queries)
        d[q[0]][q[1]] ? res.push_back(true) : res.push_back(false);
    return res;
}