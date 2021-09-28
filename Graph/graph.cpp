#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class DisjointSet
{
public:
    DisjointSet();
    int find(int x);
    void to_union(int x1, int x2);
    bool is_same(int x1, int x2);

private:
    int parent[100];
};

class Digraph
{
public:
    int count;
    Digraph();
    int ajacent[100][100];
    bool visited[100];
    void Creategraph(int n, int m);
    void createWeightedGraph(int n, int m);
    void DFS(int v, int n);
    void BFS(int v, int n);
    int indegree(int v, int n);   //求入度//
    void TopologicalOrder(int n); //有向无环图的拓扑排序//
    void Prim(int n);
    void Kruscal(int n);
};

DisjointSet::DisjointSet()
{
    for (int i = 0; i < 100; i++)
        parent[i] = i;
}

int DisjointSet::find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool DisjointSet::is_same(int x1, int x2)
{
    return find(x1) == find(x2);
}

void DisjointSet::to_union(int x1, int x2)
{
    int p1 = find(x1);
    int p2 = find(x2);
    parent[p1] = p2;
}

Digraph::Digraph()
{
    count = 0;
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
}

void Digraph::createWeightedGraph(int n, int m) //生成无权图
{
    int a, b, w;
    for (int i = 0; i < n; i++) //对角线设置为0
    {
        ajacent[i][i] = 0;
    }
    for (int i = 0; i < m; i++) //输入边权
    {
        cin >> a >> b ;
        ajacent[a][b] = 1;
        // ajacent[b][a] = 1;
    }
}

void Digraph::Creategraph(int n, int m) //生成无向带权图
{
    int a, b;
    for (int i = 0; i < n; i++) //对角线设置为0
    {
        ajacent[i][i] = 0;
    }
    for (int i = 0; i < m; i++) //输入边权
    {
        cin >> a >> b;
        ajacent[a][b] = 1;
        ajacent[b][a] = 1;
    }
}

void Digraph::DFS(int v, int n)
{
    cout << v << " ";
    visited[v] = true;
    count++;
    if (count == n)
        return;
    for (int i = 0; i < n; i++)
    {
        if (ajacent[v][i] && !visited[i])
        {
            DFS(i, n);
        }
    }
}

void Digraph::BFS(int v, int n)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (ajacent[t][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

/*  有向无环图的拓扑排序原理：
    不断地遍历图中节点，找到入度为0的点并将其输出，然后删除该点后
    改变剩下点的入度，继续上述步骤直到遍历完成*/
void Digraph::TopologicalOrder(int n)
{
    int t=0, count = 0;
    while (count < n)
    {
        for (int i = 0; i < n; i++) //遍历所有节点
        {
            bool nonIndegree = false;
            if (indegree(i, n) == 0 && !visited[i]) //找到入度为0且尚未访问的节点
            {
                t = i;
                cout << t << " ";
                nonIndegree = true;
                visited[t] = true;
                count++;
            }
            for (int i = 0; i < n; i++) //更新所有节点的入度
            {
                if (nonIndegree &&  ajacent[t][i] > 0)
                    ajacent[t][i]--;
            }
        }
    }
}

int Digraph::indegree(int v, int n)
{
    int degree = 0;
    for (int i = 0; i < n; i++)
    {
        degree += ajacent[i][v];
    }
    return degree;
}

/* Prim 算法：
1、任意选出一个点作为初始顶点,标记为book,计算所有与之相连接的点的距离，选择距离最短的，标记book.
2、重复以下操作，直到所有点都被标记为book：
在剩下的点中，计算与所有已标记book点距离最小的点，标记book,加入最小生成树。 */
void Digraph::Prim(int n)
{
    vector<int> MST;            //存放最小生成树边权值
    vector<pair<int, int>> res; //存放最小生成树边的两端点
    int mst = 0;                //最小生成树边权总和
    int index1 = 0, index2 = 0; //当前循环中另一个待连接的端点
    int count = 0;              //已访问节点个数
    visited[0] = true;          //标记已访问节点
    while (count < n - 1)       //n个节点，只要n-1次遍历即可
    {
        int Min = 10000;            //临时变量，记录每次遍历最小边权值
        for (int k = 0; k < n; k++) //遍历所有节点
        {
            if (visited[k]) //找到所有已访问的节点
            {
                int i = k;
                for (int j = 0; j < n; j++) //遍历所有与已访问节点相连的节点
                {
                    if (i != j && !visited[j] && ajacent[i][j] < Min && ajacent[i][j] > 0) //如果该节点没访问过且边权小
                    {
                        Min = ajacent[i][j]; //更新最小边权
                        index1 = i;          //更新节点
                        index2 = j;
                    }
                }
            }
        }
        visited[index2] = true;
        MST.push_back(Min);
        if (index1 <= index2) //根据点的大小按顺序存入数组
            res.push_back({index1, index2});
        else
            res.push_back({index2, index1});
        count++;
    }
    sort(MST.begin(), MST.end()); //按边权排序
    for (int i = 0; i < MST.size(); i++)
    {
        mst += MST[i];
        for (int j = 0; j < res.size(); j++)
        {
            if (ajacent[res[j].first][res[j].second] == MST[i]) //找到该边权值对应的端点
                cout << res[j].first << " " << res[j].second << " " << MST[i] << endl;
        }
    }
    cout << mst; //输出总边权最小值
}

/* kruscal算法：从所有边中选择权重最小的放入优先队列，重复步骤直到所有点都被遍历
   注意：这里选择的边的两个顶点需要没有公共祖先，即并查集不在同一个集合中
 */
void Digraph::Kruscal(int n)
{
    DisjointSet s;
    priority_queue<int, vector<int>, greater<int>> q;
    int count = 0;
    int MST = 0;
    int index1, index2;
    while (count < n - 1)
    {
        int Min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ajacent[i][j] > 0 && ajacent[i][j] < Min && (!visited[i] || !visited[j]) && !s.is_same(i, j))
                {
                    Min = ajacent[i][j];
                    index1 = i;
                    index2 = j;
                }
            }
        }
        s.to_union(index1, index2);
        visited[index1] = visited[index2] = true;
        q.push(ajacent[index1][index2]);
        count++;
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        MST += q.top();
        q.pop();
    }
    cout << MST << endl;
}

int main()
{
    return 0;
}
