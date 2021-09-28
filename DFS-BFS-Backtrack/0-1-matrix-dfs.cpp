#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, bool &path)
{
    int m = grid.size();
    int n = grid[0].size();
    if (x == m - 1 && y == n - 1)
    {
        path = true;
        return;
    }
    visited[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int x1 = x + dir[k][0];
        int y1 = y + dir[k][1];
        if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && !visited[x1][y1] && grid[x1][y1] != grid[x][y])
            dfs(grid, x1, y1, visited, path);
    }
    visited[x][y] = false;
}

int main()
{
    int m, n;
    bool path = false;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    dfs(grid, 0, 0, visited, path);
    cout << path;
    return 0;
}