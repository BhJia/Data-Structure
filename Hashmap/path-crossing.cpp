#include<bits/stdc++.h>
using namespace std;
// 判断路径是否相交：给定一个字符串path,表示东南西北的方位词，判断路径是否有相交的点。
// 思路：用哈希表记录坐标是否访问，每次移动更新坐标，判断是否访问过
bool isPathCrossing(string path)
{
    map<pair<int, int>, bool> visit;
    int x = 0, y = 0;
    visit[{0, 0}] = true;
    for (char ch : path)
    {
        if (ch == 'N')
            y++;
        else if (ch == 'S')
            y--;
        else if (ch == 'E')
            x++;
        else
            x--;
        if (visit[{x, y}])
            return true;
        visit[{x, y}] = true;
    }
    return false;
}