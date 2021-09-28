#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 给出两个list,返回两个list的共同元素且下标索引之和最小
// 思路：双哈希表分表将两个list的元素和下标对应
vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    map<string, int> m1, m2;
    for (int i = 0; i < list1.size(); i++)//将list1的元素和下标对应
        m1[list1[i]] = i;
    for (int i = 0; i < list2.size(); i++)//将list2的元素和下标对应
        m2[list2[i]] = i;
    vector<string> tmp, res;
    for (auto p : m1)      //将公共元素放入临时数组
    {
        if (m2.count(p.first))
            tmp.push_back(p.first);
    }
    //按照下标和升序自定义排序
    sort(tmp.begin(), tmp.end(), [&](string &a, string &b) { return m1[a] + m2[a] < m1[b] + m2[b]; });
    int minindex = m1[tmp[0]] + m2[tmp[0]];
    for (auto i : tmp) //验证有没有相同的最小和
    {
        if (m1[i] + m2[i] == minindex)
            res.push_back(i);
    }
    return res;
}