#include <iostream>
#include <vector>
using namespace std;
/*
买卖股票的最佳时机：
1、状态定义：dp[i]表示到第i天的最小价格
2、转移方程：dp[i]=min(dp[i-1],prices[i]); 
3、初始状态：dp[0]=prices[0];
4、返回值：全局变量profit,求每天价格减去到前一天之前的最小价格
*/
int maxProfit(vector<int> &prices)
{
    if (prices.size()<=1)return 0;
    int profit = 0;
    int dp[prices.size()];
    dp[0] = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i] = min(dp[i - 1], prices[i]);
        profit = max(profit, prices[i] - dp[i - 1]);
    }
    return profit;
}