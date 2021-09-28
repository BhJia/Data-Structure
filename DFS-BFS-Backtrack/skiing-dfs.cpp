#include <iostream>
#include <vector>
using namespace std;
int Map[111][111];
int m, n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int mark[111][111] = {0}; //对走过的点进行标记
bool isValid(int x, int y, int x1, int y1)
{
    return mark[x1][y1] == 0 && Map[x1][y1] < Map[x][y] && x1 >= 0 && y1 >= 0 && x1 < m && y1 < n;
}

void init() //初始化mark数组
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mark[i][j] = 0;
        }
    }
}

int dfs(int x, int y) 
{
    int res = 1;    //最大步数
    mark[x][y] = 1; //标记(x,y)
    for (int i = 0; i < 4; i++) //朝四个方向递归//
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if (isValid(x, y, x1, y1))
            res = max(res,dfs(x1,y1)+1);
    }
    mark[x][y] = 0; //回溯并撤销标记
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
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}