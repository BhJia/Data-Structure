#include <bits/stdc++.h>
using namespace std;
// 最大的三角形面积：给定一个点集，求由任意三点构成的最大三角形面积：
// 利用三角形面积公式：已知三点坐标（a，b）、（c，d）、（e，f），直接用公式：S=0.5 * abs(ad + cf + be - af - de - bc)
double largestTriangleArea(vector<vector<int>> &p)
{
    int res = 0, n = p.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                res = max(res, abs(p[i][0] * p[j][1] + p[i][1] * p[k][0] + p[j][0] * p[k][1] - p[i][0] * p[k][1] - p[i][1] * p[j][0] - p[j][1] * p[k][0]));
    return res * 0.5;
}