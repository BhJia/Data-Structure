#include<bits/stdc++.h>
using namespace std;
// 钥匙和房间：给定n个房间(0,1,2....n-1),每个房间都有一些钥匙可以进入别的房间,判断是否可以进入所有房间
// 题目转换为给定一个无向图,判断是否存在一个孤立的点
// BFS：遍历所有房间判断是否存在没有访问的房间
bool canVisitAllRooms_BFS(vector<vector<int>> &rooms)
{
    vector<int> visited(rooms.size(), 0);
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int key : rooms[t])
        {
            if (!visited[key])
            {
                q.push(key);
                visited[key] = 1;
            }
        }
    }
    for (auto room : visited)
        if (!room)
            return false;
    return true;
}