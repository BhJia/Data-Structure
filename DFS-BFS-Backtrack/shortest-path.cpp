#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 最短路径：找一条从二进制矩阵左上角到右下角的路径,满足：
// 1、路径上点全为0     2、能向上下左右斜对角八个方向移动  
//如果存在，返回经过的单元格总数,否则返回-1
int dir1[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dir2[4][2] = {{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0])
        return -1;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 0)); //存储路径长度
    vector<vector<int>> mark(m, vector<int>(n, 0));//标记走过的点
    queue<pair<int, int>> q; 
    q.push({0, 0});
    mark[0][0] = 1;
    dist[0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dir1[i][0];
            int y1 = y + dir1[i][1];
            int x2 = x + dir2[i][0];
            int y2 = y + dir2[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !mark[x1][y1] && !grid[x1][y1])
            {
                q.push({x1, y1});
                mark[x1][y1] = 1;
                dist[x1][y1] = dist[x][y] + 1;
            }
            if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && !mark[x2][y2] && !grid[x2][y2])
            {
                q.push({x2, y2});
                mark[x2][y2] = 1;
                dist[x2][y2] = dist[x][y] + 1;
            }
        }
    }
    return dist[m - 1][n - 1] > 0 ? dist[m - 1][n - 1] : -1;
}