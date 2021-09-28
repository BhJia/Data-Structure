#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int Map[111][111];
int m, n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// mark数组记录走到当前的节点的最大的步数
int mark[111][111] = {0};
bool isValid(int x, int y, int x1, int y1)
{
    return x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && Map[x1][y1] < Map[x][y];
}

void init()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mark[i][j] = 0;
        }
    }
}

//注意：单源bfs不需要进行标记，因为bfs是多路径一起向四周走，所以所有路径走到同一点的时候要比较并选择最长的一条
int bfs(int x, int y)
{
    int res = 0;    // 当前最大的步数
    mark[x][y] = 1; // 第一步
    queue<pair<int, int>> q;
    pair<int, int> p(x, y);
    q.push(p);
    res++;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        res = max(res, mark[x][y]);  // 更新res
        for (int i = 0; i < 4; i++) //朝四个方向递归//
        {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            pair<int, int> p1(x1, y1);
            if (isValid(x, y, x1, y1))
            {
                // 更新mark(不同的走法中选择步数最大的)
                mark[x1][y1] = max(mark[x1][y1], mark[x][y] + 1);
                q.push(p1);
            }
        }
    }
    return res;
}
 
int main()
{
    cin >> m >> n;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            init();
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}