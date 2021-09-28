#include<bits/stdc++.h>
using namespace std;
// 二维矩阵区域求和：给定二维矩阵两点坐标,求以两点坐标为左上角和右下角的矩阵元素和
// 暴力解法不写了超时了
// 二维前缀和动态规划写法
vector<vector<int>> temp;//二维矩阵
int sumRegion(int row1, int col1, int row2, int col2)
{
    if (temp.empty())
        return 0;
    vector<vector<int>> dp(temp.size(), vector<int>(temp[0].size()));
    dp[row1][col1] = temp[row1][col1];    //dp[i][j]表示以(i,j)为右下角的矩阵元素和
    for (int i = col1 + 1; i <= col2; i++) //初始化第一行
        dp[row1][i] = dp[row1][i - 1] + temp[row1][i];
    for (int i = row1 + 1; i <= row2; i++)  //初始化第一列
        dp[i][col1] = dp[i - 1][col1] + temp[i][col1];
    for (int i = row1 + 1; i <= row2; i++)  
        for (int j = col1 + 1; j <= col2; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp[i][j];  //德摩根定律
    return dp[row2][col2];
}
