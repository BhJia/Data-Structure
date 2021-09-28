#include <bits/stdc++.h>
using namespace std;
// 0-1背包问题母代码(二维)
void bags()
{
    vector<int> weight = {1, 3, 4};   //各个物品的重量
    vector<int> value = {15, 20, 30}; //对应的价值
    int bagWeight = 4;                //背包最大能放下多少重的物品

    // 二维数组：状态定义:dp[i][j]表示从0-i个物品中选择不超过j重量的物品的最大价值
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

    // 初始化:第一列都是0，第一行表示只选取0号物品最大价值
    for (int j = bagWeight; j >= weight[0]; j--)
        dp[0][j] = dp[0][j - weight[0]] + value[0];

    // weight数组的大小 就是物品个数
    for (int i = 1; i < weight.size(); i++) // 遍历物品(第0个物品已经初始化)
    {
        for (int j = 0; j <= bagWeight; j++) // 遍历背包容量
        {
            if (j < weight[i])           //背包容量已经不足以拿第i个物品了
                dp[i][j] = dp[i - 1][j]; //最大价值就是拿第i-1个物品的最大价值
            //背包容量足够拿第i个物品,可拿可不拿：拿了最大价值是前i-1个物品扣除第i个物品的重量的最大价值加上i个物品的价值
            //不拿就是钱i-1个物品的最大价值,两者进行比较取较大的
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}

// 一维
//状态定义：dp[j]表示容量为j的背包能放下东西的最大价值
void test_1_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--)
        {                                                     // 遍历背包容量(一定要逆序)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); //不取或者取第i个
        }
    }
    cout << dp[bagWeight] << endl;
}

/* 
背包问题解题思路模板：
(一)背包问题判别：  
给定一个target(背包容量)，target可以是数字也可以是字符串，
再给定一个数组nums(物品)，nums中装的可能是数字，也可能是字符串，问：能否使用nums中的元素做各种排列组合得到target

(二)解题模板：
遍历顺序：
1、0-1背包：外循环nums,内循环target,且target倒序/target>=nums[i]
2、完全背包:外循环nums,内循环target,且target正序/target>=nums[i]
3、考虑元素顺序的组合问题:外循环target,内循环nums,target>=nums[i]
注意：1、2可以和3结合为考虑顺序/不考虑顺序的组合问题,并且优先考虑顺序(即如果考虑顺序外循环target,内循环nums)

状态方程转移：
1、最值问题: dp[i] = max/min(dp[i], dp[i-nums]+1)或dp[i] = max/min(dp[i], dp[i-num]+nums);
2、存在问题(bool)：dp[i]=dp[i]||dp[i-num];
3、组合问题：dp[i]+=dp[i-num]; 

初始化：一般初始定义dp(target+1)
*/

/* 实例分析 */
// 分割等和子集：判断是否能将一个数组分割为两个子集,其和相等
// 0-1背包存在性问题：是否存在一个子集,其和为target=sum/2,外循环nums,内循环target倒序,应用状态方程2
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
        return false;
    int target = sum / 2;
    vector<int> dp(target + 1, 0); //dp[i]:是否存在子集和为i
    dp[0] = true;
    for (int num : nums)
        for (int i = target; i >= num; i--)
            dp[i] = dp[i] || dp[i - num];
    return dp[target];
}

// 零钱兑换：给定amount,求用任意数量不同面值的零钱换到amount所用的最少数量
// 完全背包最值问题：外循环coins,内循环amount正序,应用状态方程1
int coinChange(vector<int> &coins, int amount)
{
    vector<long long> dp(amount + 1, INT_MAX); //给dp数组每个位置赋初值为INT_MAX是为了最后判断是否能填满amount,故要用long long 类型
    dp[0] = 0;                                 //dp[i]:换到面值i所用的最小数量
    for (int coin : coins)
    {
        for (int i = 0; i <= amount; i++)
        {
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// 目标和：给数组里的每个数字添加正负号得到target
// 数组和sum,目标和s, 正数和x,负数和y,则x+y=sum,x-y=s,那么x=(s+sum)/2=target
// 0-1背包不考虑元素顺序的组合问题:选nums里的数得到target的种数,外循环nums,内循环target倒序,应用状态方程3
int findTargetSumWays(vector<int> &nums, int s)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + s) % 2 != 0 || sum < s)
        return 0;
    int target = (sum + s) / 2;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int num : nums)
        for (int i = target; i >= num; i--)
            dp[i] += dp[i - num];
    return dp[target];
}

// 完全平方数：对于一个正整数n,找出若干个完全平方数使其和为n,返回完全平方数最少数量
// 完全背包的最值问题：完全平方数最小为1,最大为sqrt(n),故题目转换为在nums=[1,2.....sqrt(n)]中选任意数平方和为target=n
// 外循环nums,内循环target正序,应用转移方程1
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX); //dp[i]:和为i的完全平方数的最小数量
    dp[0] = 0;
    for (int num = 1; num <= sqrt(n); num++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i >= num * num)
                dp[i] = min(dp[i], dp[i - num * num] + 1);
        }
    }
    return dp[n];
}

//组合总和IV：在nums中任选一些数,和为target
// 考虑顺序的组合问题：外循环target,内循环nums,应用状态方程3
int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int num : nums)
        {
            if (num <= i) //这题力扣写的时候要加上这样的判断：dp[i - num] < INT_MAX - dp[i]不然会溢出
                dp[i] += dp[i - num];
        }
    }
    return dp[target];
}

// 零钱兑换2：任选硬币凑成指定金额,求组合总数
// 完全背包不考虑顺序的组合问题：外循环coins,内循环target正序,应用转移方程3
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins)
        for (int i = 1; i <= amount; i++)
            if (i >= coin)
                dp[i] += dp[i - coin];
    return dp[amount];
}

// 最后一块石头的重量：从一堆石头中,每次拿两块重量分别为x,y的石头,若x=y,则两块石头均粉碎;若x<y,两块石头变为一块重量为y-x的石头
// 求最后剩下石头的最小重量(若没有剩下返回0)
// 问题转化为：把一堆石头分成两堆,求两堆石头重量差最小值
// 进一步分析：要让差值小,两堆石头的重量都要接近sum/2;我们假设两堆分别为A,B,A<sum/2,B>sum/2,若A更接近sum/2,B也相应更接近sum/2
// 进一步转化：将一堆stone放进最大容量为sum/2的背包,求放进去的石头的最大重量MaxWeight,最终答案即为sum-2*MaxWeight;、
// 0/1背包最值问题：外循环stones,内循环target=sum/2倒叙,应用转移方程1
int lastStoneWeightII(vector<int> &stones)
{
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<int> dp(target + 1);
    for (int stone : stones)
        for (int i = target; i >= stone; i--)
            dp[i] = max(dp[i], dp[i - stone] + stone);
    return sum - 2 * dp[target];
}

// 投掷骰子的方法数：d个骰子,每个有f个面(点数为1,2,...f),求骰子点数和为target的方法
// 分组0/1背包的组合问题：dp[i][j]表示投掷i个骰子点数和为j的方法数;三层循环：最外层为背包d,然后先target后点数f
// 应用二维的转移方程3：dp[i][j]+=dp[i-1][j-f];
int numRollsToTarget(int d, int f, int target)
{
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= target; j++)
            for (int k = 1; k <= f && j >= k; k++)
                dp[i][j] += dp[i - 1][j - k];
    return dp[d][target];
}