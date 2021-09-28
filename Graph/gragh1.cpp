#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
vector<int> indegree;
vector<bool> visited;
// 并查集标准模板
int parent[1001];
void init()
{
    for (int i = 0; i < 1001; ++i)
        parent[i] = i;
}

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void to_union(int x1, int x2)
{
    int p1 = find(x1);
    int p2 = find(x2);
    if (p1 == p2)
        return;
    parent[p1] = p2;
}

bool isSame(int x1, int x2)
{
    return find(x1) == find(x2);
}

//邻接表构建有向图,并求入度
void createGraph(int n, int m)
{
    edges.resize(n);
    indegree.resize(n);
    visited.resize(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }
}

// 邻接表构建无向图
void createGraph1(int n, int m)
{
    edges.resize(n);
    visited.resize(n);
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

// DFS
void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (int u : edges[v])
        if (!visited[u])
            dfs(u);
}

// BFS
void bfs()
{
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto &u : edges[v])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = 1;
            }
        }
    }
}

//拓扑排序
void topological(int n)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int v : edges[t])
            if (--indegree[v] == 0)
                q.push(v);
    }
}

// Kruskal求最小生成树(edge first:边权 second :顶点)
int kruskal(vector<pair<int, pair<int, int>>> &edge)
{
    init();
    sort(edge.begin(), edge.end(), [&](pair<int, pair<int, int>> &p, pair<int, pair<int, int>> &q)
         { return p.first < q.first; }); //按边权升序
    int res = 0;
    for (auto i : edge)
    {
        if (!isSame(i.second.first, i.second.second)) //如果不在并查集
        {
            res += i.first;
            to_union(i.second.first, i.second.second);
        }
    }
    return res;
}

int main()
{
    int n,m;
    cin >> n >> m;
    
    return 0;
}