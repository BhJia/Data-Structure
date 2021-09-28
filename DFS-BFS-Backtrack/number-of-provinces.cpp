#include <iostream>
#include <vector>
using namespace std;
//省份数量：一组相连的城市是一个省，计算图中省的个数
// 图的遍历,遍历所有节点,每次dfs就是一个省
bool visited[200] = {0};
int findCircleNum(vector<vector<int>> &isConnected)
{
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
            dfs(i, isConnected);
            count++;
    }
    return count;
}

void dfs(int v, vector<vector<int>> &isConnected)
{
    visited[v] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[v][i] && !visited[i])
            dfs(i, isConnected);
    }
}