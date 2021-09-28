#include<bits/stdc++.h>
using namespace std;
/*
最小路径和：在矩阵找一条从左上角到右下角的路径,使路径之和最小
动态规划解题：
1、 状态定义：dp[i][j]表示从出发点走到grid[i][j]的最小路径和
2、转移方程：在非边界的情况下,走到grid[i][j]的最小路径是走到grid[i-1][j]和grid[i][j-1]的路径的最小值,加上该点的值
3、初始状态：dp[0][0]=grid[0][0];并且第一行和第一列的边界要单独初始化
4、返回值:返回dp[m-1][n-1](m,n为矩阵的行、列数)
 */

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    return dp[m - 1][n - 1];
}

// 带障碍的最小路径
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

// 三角形最短路径：给定一个正三角形路径，每次只能从一个点往下一层相邻左右两个点走，求自顶而下的最小路径
//1、状态定义：dp[i][j]表示到triangle[i][j]的最小路径和
//2、转移方程：dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
//3、初始状态：左边界dp[i][0]以及右边界dp[i][i]都要初始化
//4、返回值：遍历dp数组最后一层最小值即为返回值
int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    for (int i = 2; i < m; i++)
        for (int j = 1; j < i; j++)
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
}

// 改进：用原地算法,在原数组上修改
int minimumTotal2(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    for (int i = 1; i < m; i++)
    {
        triangle[i][0] += triangle[i - 1][0];
        triangle[i][i] += triangle[i - 1][i - 1];
    }
    for (int i = 2; i < m; i++)
        for (int j = 1; j < i; j++)
            triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    return *min_element(triangle[m - 1].begin(), triangle[m - 1].end());
}

// 正方形最短路径：与三角形路径走法完全一致
// 注意：可以使用原地动态规划,在原二维矩阵上修改减少空间使用
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                matrix[i][j] += min(matrix[i - 1][0], matrix[i - 1][1]);
            else if (j == n - 1)
                matrix[i][j] += min(matrix[i - 1][n - 1], matrix[i - 1][n - 2]);
            else
                matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i - 1][j + 1]));
        }
    }
    return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
}

// 出界的路径数：给定一个m*n的网格和、球的坐标(x,y)、最多移动步数N,球每次可以向四个方向移动一格,求它走出界的路径种数
// 这第一眼看到想到的就是DFS暴力递归,结果超时了
int curstep = 0;
int path = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int mod = pow(10, 9) + 7;
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, 0));
    dfs(startRow, startColumn, m, n, maxMove, 0, visited);
    return path;
}

void dfs(int x, int y, int m, int n, int N, int cur, vector<vector<bool>> &visited)
{
    if (cur > N)
        return;
    if (x < 0 || y < 0 || x >= m || y >= n)
    {
        path++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        dfs(x1, y1, m, n, N, cur + 1, visited);
    }
    visited[x][y] = false;
}