#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool path = false;
void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        int x1 = q.front().first;
        int y1 = q.front().second;
        if(x1==m-1&&y1==n-1)
        {
            path = true;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++) //朝四个方向递归//
        {
            int x2 = x1 + dir[i][0];
            int y2 = y1 + dir[i][1];
            if (x2 >= 0 && y2 >= 0 && x2 < m && y2 < n && !visited[x2][y2] && grid[x2][y2] != grid[x1][y1])
            {
                q.push({x2,y2});
                visited[x2][y2] = true;
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    bfs(grid, 0, 0, visited);
    cout << path;
    return 0;
}