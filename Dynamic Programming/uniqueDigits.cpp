#include<bits/stdc++.h>
using namespace std;
// 各个数位数字不同的个数：求0到n位数最后一个数中,各位数字不相同的数的个数
// 先上暴力解法,遍历所有数用哈希表找出重复的即可,显然超时了
bool hasSameDigit(int n)
{
    map<int, int> m;
    while (n)
    {
        if (++m[n % 10] > 1)
            return true;
        n /= 10;
    }
    return false;
}

int countNumbersWithUniqueDigits(int n)
{
    int count = 0;
    for (int i = 0; i < pow(10, n); i++)
        if (hasSameDigit(i))
            count++;
    return pow(10, n) - count;
}

// 动态规划思路：dp[i]表示i位数各位出现重复数字的数的个数,那么分两种情况：
// 1、若前i-1位已经有重复的了,那么第i位取0-9都可以  2、若前i-1位没有重复的,那么第i位取前i-1位的任意一个数都可以
int countNumbersWithUniqueDigits(int n)
{
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] * 10 + (9 * pow(10, i - 2) - dp[i - 1]) * (i - 1);
    return pow(10, n) - accumulate(dp.begin(), dp.end(), 0);
}