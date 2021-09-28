#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//图像渲染：以(sr,sc)为中心点向四个方向扩展，并把与中心点像素相同的点值改成newColor
//典型的单源bfs，简单题
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int t = image[sr][sc];
    if (t == newColor)
        return image;
    int m = image.size(), n = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && image[x1][y1] == t)
            {
                q.push({x1, y1});
                image[x1][y1] = newColor;
            }
        }
    }
    return image;
}