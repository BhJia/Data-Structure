#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
/* 在给定的网格中，每个单元格可以有以下三个值之一：
值 0 代表空单元格，值 1 代表新鲜橘子，值 2 代表腐烂的橘子。 
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。 */
/* 方法：多源BFS问题:把所有的源头加入队列，然后分别bfs向外扩展，并记录 */
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q; //存储坐标对组的队列
    int res = 0;             //所有橘子腐烂的最小时间
    int m = grid.size();     
    int n = grid[0].size();  
    //把所有腐烂橘子加入队列(所有源头)
    for (int i = 0; i < m; i++)     
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    //基本bfs操作
    while (!q.empty())
    {
        int count = q.size();
        for (int j = 0; j < count; j++)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x1 = p.first + dir[i][0];
                int y1 = p.second + dir[i][1];
                if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && grid[x1][y1] == 1)
                {
                    grid[x1][y1] = 2; //该橘子腐烂(这里用橘子腐烂直接代替标记数组)
                    q.push({x1, y1}); //加入队列
                }
            }
        }
        if (!q.empty()) //此时队列不空，说明还有新鲜橘子，那么时间+1
            res++;
    }
    //判断所有源头感染完毕后还有没有新鲜橘子无法被感染
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return res;
}

//求矩阵每个点与最近的0的距离：与腐烂的橘子类似，都是多源BFS
// 模板：先把所有源点入队，再分别向四周bfs，同时记录走过的距离，扩展一次距离+1
// 注意：多源bfs一定要标记搜索过的点
vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();    //矩阵长宽
    vector<vector<int>> dist(m, vector<int>(n, 0)); //存储走过的距离
    vector<vector<int>> mark(m, vector<int>(n, 0)); //标记走过的点
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) //把所有0加入队列
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
                q.push({i, j});
        }
    }
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && matrix[x1][y1] == 1 && !mark[x1][y1])
            {
                dist[x1][y1] = dist[x][y] + 1;
                q.push({x1, y1});
                mark[x1][y1] = 1;
            }
        }
    }
    return dist;
}

//地图分析：求所有海洋与最近的陆地距离的最大值
// 同样的多源bfs问题，不同点在于要比较每次距离的最大值
int maxDistance(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 0));
    vector<vector<int>> mark(m, vector<int>(n, 0));
    int res = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    if (q.size() == 0 || q.size() == m * n)
        return -1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] == 0 && !mark[x1][y1])
            {
                dist[x1][y1] = dist[x][y] + 1;
                res = max(res, dist[x1][y1]);
                q.push({x1, y1});
                mark[x1][y1] = 1;
            }
        }
    }
    return res;
}

// 1765、地图中最高点
vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (isWater[i][j])
                q.push({i, j});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && !isWater[x1][y1])
            {
                height[x1][y1] = height[x][y] + 1;
                isWater[x1][y1] = 1;
                q.push({x1, y1});
            }
        }
    }
    return height;
}