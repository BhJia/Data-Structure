#include<bits/stdc++.h>
using namespace std;
// 最小绝对差：给定一个数组,求所有不考虑顺序的数对中差的绝对值最小的所有数对，并按照首元素升序排列
// 思路一：暴力枚举所有数对，存储到二维数组中，自定义排序
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            res.push_back(temp);
        }
    }
    sort(res.begin(), res.end(), [&](vector<int> &a, vector<int> &b) {
        return (a[1] - a[0] < b[1] - b[0]) || (a[1] - a[0] == b[1] - b[0] && a[0] < b[0]);
    });
    int index = 0;
    int x = res[0][1] - res[0][0];
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i][1] - res[i][0] > x)
        {
            index = i;
            break;
        }
    }
    return vector<vector<int>>(res.begin(), res.begin() + index);
}

// 思路2：升序排序后一遍遍历，比较相邻两个数差值与当前最小差值，如果小就更新最小差值并把两个数加入答案；如果相等直接加入答案
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    vector<vector<int>> res;
    int mindif = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        int cur = arr[i] - arr[i - 1];
        if (cur < mindif)
        {
            res.clear();
            res.push_back({arr[i - 1], arr[i]});
            mindif = cur;
        }
        else if (cur == mindif)
            res.push_back({arr[i - 1], arr[i]});
    }
    return res;
}