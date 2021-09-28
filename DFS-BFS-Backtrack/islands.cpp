#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// 判断岛屿数量：扫描整个二维网格。如果一个位置为 1，则以其为起始节点进行dfs。
// 每个搜索到的 1 都会被重新标记为 0(相当于mark数组的功能),最终岛屿的数量就是dfs的次数。 
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == '1')
            {
                count++;
                dfs(grid, row, col);
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>> &grid, int row, int col)
{
    grid[row][col] = '0'; //把扫描到的1标记为0,实际上实现了一个mark数组的功能
    for (int i = 0; i < 4; i++)
    {
        int row1 = row + dir[i][0];
        int col1 = col + dir[i][1];
        if (isValid(grid, row1, col1))
            dfs(grid, row1, col1);
    }
}

bool isValid(vector<vector<char>> &grid, int row, int col)
{
    int m = grid.size();
    int n = grid[0].size();
    return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
}



//求最大的岛屿面积
//与岛屿数量类似:遇到1,以该点作为起始点向四周进行dfs，走一步面积+1，最后比较每次dfs面积大小即可
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
            {
                res = max(res, dfs(grid, row, col));
            }
        }
    }
    return res;
}

int dfs(vector<vector<int>> &grid, int row, int col)
{
    grid[row][col] = 0;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int row1 = row + dir[i][0];
        int col1 = col + dir[i][1];
        if (isValid(grid, row1, col1))
            count += dfs(grid, row1, col1);
    }
    return count;
}

bool isValid(vector<vector<int>> &grid, int row, int col)
{
    int m = grid.size();
    int n = grid[0].size();
    return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1;
}

// 求出所有水域大小：dfs框架与上面岛屿面积类似(int型dfs),区别在于这里的岛屿可以向斜对角扩展，即八个方向
int dir1[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dir2[4][2] = {{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
vector<int> pondSizes(vector<vector<int>> &land)
{
    vector<int> res;
    int m = land.size();
    int n = land[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (land[i][j] == 0)
            {
                res.push_back(dfs(land, i, j));
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int dfs(vector<vector<int>> &land, int x, int y)
{
    int m = land.size();
    int n = land[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) //注意剪枝
        return 0;
    land[x][y] = 1;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dir1[i][0];
        int y1 = y + dir1[i][1];
        int x2 = x + dir2[i][0];
        int y2 = y + dir2[i][1];
        count += dfs(land, x1, y1);
        count += dfs(land, x2, y2);
    }
    return count;
}

//一个棋盘,每个点只有X或O,现在要把所有四周被X围住的O变成X
//思路:没被包围的O说明在边界上或者与边界上的O直接或间接相连
//则只需要先遍历棋盘找到边界上的O,然后广搜把周围与其相连的O变成A,然后再次遍历棋盘,把没有标记的O变成X,再把A恢复成O即可
void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                board[i][j] = 'A';
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int x1 = x + dir[k][0];
                        int y1 = y + dir[k][1];
                        if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && board[x1][y1] == 'O')
                        {
                            board[x1][y1] = 'A';
                            q.push({x1, y1});
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X')
                continue;
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else
                board[i][j] = 'O';
        }
    }
}