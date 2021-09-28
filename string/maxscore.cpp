#include<bits/stdc++.h>
using namespace std;
//分割字符串最大得分：给定一个0/1字符串，任意分割，得分为左子串0的个数加上右子串1的个数，求最大得分
// 调用count函数统计个数
int maxScore(string s)
{
    int res = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int score = count(s.begin(), s.begin() + i, '0') + count(s.begin() + i, s.end(), '1');
        res = max(res, score);
    }
    return res;
}