#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//合并区间:给定若干个区间,将可以合并的区间合并
//自定义排序：先按照每个区间的起始端点升序排序,将第一个区间放入res数组
// 然后从第二个开始此区间比较，如果左端点小于右端点，代表有重合，更新右端点，否则无重合，直接加入res
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    if (intervals.empty())
        return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= res[res.size() - 1][1])
        {
            res[res.size() - 1][1] = max(res[res.size() - 1][1], intervals[i][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

// 用最少的箭扎破气球:数组每个区间代表每个气球直径端点在x轴上的坐标,在x轴上垂直扎下去把气球扎破最少要用多少箭
//思路:和合并区间思路类似，先按照左端点升序排序
//算法:两个不重合区间必要两支箭,两个重合区间只要一支箭，但第三个区间的左端点必须在前两个区间偏左的右端点左边才能一支箭扎破三个区间
int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
        return 0;
    sort(points.begin(), points.end(), cmp);
    int res = 1;
    for (int i = 0; i < points.size() - 1; i++)
    {
        if (points[i][1] < points[i + 1][0]) //两个区间不重合
            res++;
        else //两个区间重合：更新右区间的右端点为两个区间偏左右端点,则下一次循环用第三个区间左端点和更新后的右端点比较
            points[i + 1][1] = min(points[i][1], points[i + 1][1]);
    }
    return res;
}

//删除被覆盖区间：给定区间列表,删除被完全覆盖的区间,返回剩余区间个数
//自定义排序:先按照区间左端点升序,左端点若相同按照右端点降序，这样整个区间数组由区间大到区间小排序
static bool cmp(vector<int> &a, vector<int> &b)
{
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
}
int removeCoveredIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> res; //记录最终结果的数组
    sort(intervals.begin(), intervals.end(), cmp);
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][1] <= res[res.size() - 1][1]) //由于左端点必然升序所以不必比较，只要判断右端点的大小
            continue;                                  //如果被覆盖就不加入数组
        res.push_back(intervals[i]); //不被覆盖则加入数组
    }
    return res.size();
}