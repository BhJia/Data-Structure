#include<bits/stdc++.h>
using namespace std;
// 判断二分图：给定一个邻接点的边集，判断这个图是否为二分图
// 方法：BFS+染色。首先要知道这道题的图不是联通图，意味着这相当于多源BFS，不过不同于一般的多源BFS在开始就把所有源头放到队列中
// 本题只需要遍历所有点,对尚未访问的点进行BFS,如果相邻点染色相同那么错误,如果相邻点没有染色,就染相反颜色
// 染色问题：离散数学学过，二分图等价于对任意点都可以用两种颜色的任意一种进行染色
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);  //0表示初始状态,1和-1分别表示两种颜色
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) //如果访问过了就跳过
            continue;
        q.push(i);
        visited[i] = 1;  //染一种颜色
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : graph[u])
            {
                if (visited[v] == visited[u]) //如果邻接点中有相同颜色,那么不是二分图
                    return false;
                if (!visited[v])  //如果没被染色,就染成另一种颜色并加入队列
                {
                    q.push(v);
                    visited[v] = visited[u] * (-1);
                }
            }
        }
    }
    return true;
}