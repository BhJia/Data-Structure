#include<bits/stdc++.h>
using namespace std;
// 最大正方形：给定二维数组matrix,matrix[i][j]=1代表可以构成正方形,返回最大正方形面积
// 注意面积是不好递推的,所以将最大面积转换为最大边长
int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty()) 
        return 0;
    int res = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n)); //dp[i][j]表示以(i,j)为右下角的正方形最大边长
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)  //单独考虑第一行和第一列
                    dp[i][j] = 1;
                else   //以(i,j)为右下角正方形的最大边长是由(i-1,j),(i,j-1),(i-1,j-1)三个点为右下角的正方形的最小边长(类似木桶原理)
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            res = max(res, dp[i][j]); //更新最大边长
        }
    }
    return res * res;
}