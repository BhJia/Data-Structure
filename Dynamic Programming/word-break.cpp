#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// 单词拆分：给定一个非空字符串s和一个非空字符数组wordlist,判断s是否可以拆分为字符数组中的几个单词
/*
动态规划：
1、状态定义：dp[i]表示s从s[0]到s[i-1]的子串substr(0,i)是否能被拆分为字符数组的单词
2、转移方程：题目转换为是否存在一个i(i>=1),dp[i]=true,且substr(i,n-i)在字符数组中存在
即 dp[i]&& wordlist.count(s.substr(i,n-1));
3、初始化：默认空串满足题意,即dp[0]=true;
4、返回值：返回整个字符串，即substr(0,s.size())的真假,dp[s.size()];
*/

bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> w;
    for (auto i : wordDict)
        w.insert(i);
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
            if (dp[j] && w.count(s.substr(j, i - j)))
                dp[i] = true;
    }
    return dp[s.size()];
}