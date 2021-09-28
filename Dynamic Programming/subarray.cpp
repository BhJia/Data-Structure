#include<bits/stdc++.h>
using namespace std;
// 最长公共子数组：给定两个数组,求最长公共子数组长度
// 动态规划思路：dp[i][j]表示A[i:],B[j:]最长公共前缀,则如果A[i]!=B[j]那么最长公共前缀一定是0；
// 如果A[i]=B[j]那么最长公共前缀等于A[i+1],B[j+1]的最长公共前缀+1

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.empty() || nums2.empty())
        return 0;
    int res = 0;
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--) //注意必须反向遍历,否则i+1,j+1无意义
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j] = nums1[i] == nums2[j] ? dp[i + 1][j + 1] + 1 : 0;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

// 最长公共子序列
// 另一种方法解题：定义dp[i][j]表示text1[0:i-1]与text2[0:j-1]最长公共子序列
// 那么如果text1[i-1]=text2[j-1],公共序列长度就是dp[i-1][j-1]+1,否则由dp[i-1][j]与dp[i][j-1]的最大值决定
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[m][n];
}

// 两个字符串的删除操作：找到使 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符
// 即求删除到最长公共子序列所用的最小步数,即用总长度减去公共子序列长度即可,与上一题完全类似
int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    return m - dp[m][n] + n - dp[m][n];
}

//最长递增子序列：注意子序列不一定连续，所以我原来理解成连续的，写成的代码如下：
int findLengthOfLCIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int res = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        res = max(res, dp[i]);
    }
    return res;
}
 
// 实际上应该如下
int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);  //dp[i]表示以nums[i]结尾的最长递增子序列长度,初始化每个都为1
    int res = dp[0];     //如果res=0,那么如果nums只有一个数的话就会出错
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])               //如果找到了一个递增的,就更新dp[i]为原来的dp[i]和这个递增序列长度的较大者
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        res = max(res, dp[i]);
    }
    return res;
}


// 最长数对链：给定数对的数组,用所有数对构造最长数对链,满足跟随关系：仅当b<c时,(c,d)才能跟在(a,b)后面
// 自定义排序后转化为最长递增子序列
int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    vector<int> dp(n + 1, 1);
    dp[0] = 1;
    int res = dp[0];
    sort(pairs.begin(), pairs.end(), [&](vector<int> &p, vector<int> &q) { return p[0] < q[0]; });
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pairs[i][0] > pairs[j][1])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        res = max(res, dp[i]);
    }
    return res;
}

// 最大子数组和
int maxSubArray(vector<int> &nums)
{
    int res = nums[0];
    int dp[nums.size()];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

// 最大升序子数组和
// dp[i]表示以nums[i]结尾的递增子数组最大和
int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size(), res = nums[0];
    vector<int> dp(n + 1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = nums[i] > nums[i - 1] ? max(dp[i - 1] + nums[i], nums[i]) : nums[i];
        res = max(res, dp[i]);
    }
    return res;
}

// 乘积最大子数组
/* 与和最大子数组不同的是,数的正负会对递推产生影响：用公式dp[i]=max(dp[i-1]*nums[i],dp[i]),对正数无影响,但一旦遇到负数,
与前面子数组最大乘积的乘积反而会变成最小。 因此我们同时维护子数组的最大乘积和最小乘积,遇到正数照常计算,遇到负数交换最大乘积和
最小乘积,那么负数与最小乘积的乘积就会变成最大乘积,最后维护一个全局变量,不断更新全局最大值即可 */
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int res = nums[0], dpMax = 1, dpMin = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            swap(dpMax, dpMin);
        dpMax = max(dpMax * nums[i], nums[i]);
        dpMin = min(dpMin * nums[i], nums[i]);
        res = max(res, dpMax);
    }
    return res;
}

// 删除一次得到的子数组最大和:对一个数组所有的连续子数组,可以删除一个元素(或者不删除),求出最大的子数组和
// 与"最大子数组和"不同点在于要维护两个dp数组,dp1[i]表示以i结尾的子数组不删除元素的最大和,dp2[i]表示删除元素的最大值
// 易错点：1、题目要求子数组非空,故第一个元素不能删除,dp2[0]=a[0]而非max(a[0],0);
// 2、维护全局变量ans,比较每次删与不删的子数组最大值与ans三个遍历的大小,求最大值
int maximumSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    dp1[0] = arr[0];
    dp2[0] = arr[0];
    int ans = dp2[0];
    for (int i = 1; i < n; i++)
    {
        dp1[i] = max(dp1[i - 1] + arr[i], arr[i]); //与最大子数组和的转移方程相同
        dp2[i] = max(dp2[i - 1] + arr[i], dp1[i - 1]); //是否要删除第i个元素
        ans = max(ans, max(dp1[i], dp2[i]));
    }
    return ans;
}

// 连续字符：只包含一种字符的最长非空子串
int maxPower(string s)
{
    int n = s.size(), res = 1;
    if (n == 1)
        return 1;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
            dp[i] = dp[i - 1] + 1;
        res = max(res, dp[i]);
    }
    return res;
}