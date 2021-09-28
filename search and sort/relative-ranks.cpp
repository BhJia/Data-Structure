#include<bits/stdc++.h>
using namespace std;
// 相对名次：给定一个分数数组，分数越高名次越前；前三名分别授予金牌、银牌、铜牌，后面记录名次
vector<string> findRelativeRanks(vector<int> &score)
{
    set<int, greater<int>> s(score.begin(), score.end()); //set记录score并降序排序
    vector<string> res;
    for (auto i : score) 
    {
        int pos = distance(s.begin(), s.find(i)); //查找分数在set里的排名下标
        if (pos == 0)
            res.push_back("Gold Medal");
        else if (pos == 1)
            res.push_back("Silver Medal");
        else if (pos == 2)
            res.push_back("Bronze Medal");
        else
            res.push_back(to_string(pos + 1));
    }
    return res;
}