#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//K个离原点最近的点：给定坐标数组代表坐标,求k个离原点最近的点
//自定义排序算法
static bool cmp(vector<int> &p, vector<int> &q)
{
    int d1 = pow(p[0], 2) + pow(p[1], 2);
    int d2 = pow(q[0], 2) + pow(q[1], 2);
    return d1 < d2;
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> res;
    sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        res.push_back(points[i]);
    }
    return res;
}