#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 打家劫舍：小偷不能偷相邻两家,求偷的金额最大
/*
1、状态定义：dp[i]表示到第i间最多偷窃金额
2、转移方程：n>1时, dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
3、初始化：dp[0] = nums[0];dp[1] = max(nums[0], nums[1]);
4、返回值：dp[n-1];
 */

int rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    return dp[nums.size() - 1];
}