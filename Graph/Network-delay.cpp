#include<bits/stdc++.h>
using namespace std;
/* 
Dijkstra算法：
1、适用范围：无负权单源最短路径,即求一个点到其他各点的最短路径
2、主要思路：
贪心思想，首先把起点到所有点的距离存下来找到最短的，然后松弛一次再找出最短的，
所谓的松弛操作就是，遍历与当前最短点相连的点，看通过当前距离最短的点作为中转站会不会更近，如果更近了就更新距离，
这样把所有的点找遍之后就存下了起点到其他所有点的最短距离。

3、具体实现：
一、朴素解法：
(1)维护一个起点到所有点当前最小距离的dis数组、带权邻接矩阵weights、标记已访问点的数组visited;
(2)初始化dis数组：将所有与起始点直接相连的点的最小距离设置为该点到起始点的权值,非直接相连的设置为INT_MAX;
(3)遍历图,找出所有未访问的点中到起始点距离最短的点A,记录下标和最短距离
(4)松弛操作：遍历所有与A相邻的点B,比较A到起始点最短距离加A到B的权值与B到起始点的最短距离的大小,并更新B到起始点的最短距离
(5)选择更新后最短距离的点继续操作4,5,直到所有点都被访问
注意：整个思路最重要的就是松弛操作,一定要深入理解

二、堆优化(优先队列)
优化思路：首先把起点入队,然后对起点周围的点进行松弛,把所有松弛过的点入队,按照到起点的距离升序,那么队首元素就是当前最小距离的点,
对该点相邻的点继续进行松弛操作,直到所有点都进行更新
注意：遇到已经更新过的点不要再次更新
*/
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<int> dis(n + 1, INT_MAX);
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    vector<int> visited(n + 1, 0);
    dis[k] = 0;
    visited[k] = 1;
    for (auto i : times)    //初始化邻接矩阵
        graph[i[0]][i[1]] = i[2];
    for (int i = 1; i <= n; i++)   //初始化dis数组
        if (graph[k][i] != -1 && i != k)
            dis[i] = graph[k][i];
    int cnt = 1;
    while (cnt < n) 
    {
        int mindis = INT_MAX, index = 0; 
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dis[i] < mindis)  //找到最小距离的点和距离并记录
            {
                mindis = dis[i];
                index = i;
            }
        }
        visited[index] = 1; //标记访问
        for (int i = 1; i <= n; i++)   //松弛操作
            if (!visited[i] && graph[index][i] != -1)
                dis[i] = min(dis[i], graph[index][i] + dis[index]);
        cnt++;
    }
    int maxdis = *max_element(dis.begin() + 1, dis.end());
    return maxdis != INT_MAX ? maxdis : -1;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    typedef pair<int, int> p;
    vector<int> dis(n + 1, INT_MAX); //起始点与图中所有点的当前最短距离
    vector<int> visited(n + 1, 0);   //标记点是否更新过
    vector<vector<p>> graph(n + 1); // 带权邻接表：Key:顶点1 value.first:边权值 value.second:顶点1所有相邻点
    priority_queue<p, vector<p>, greater<p>> q; //小顶锥维护所有进行过松弛操作的点(按距离升序)
    for (auto &t : times)
        graph[t[0]].push_back({t[2], t[1]}); //初始化带权邻接表
    dis[k] = 0;
    q.push({0, k}); //把起始点入队
    while (!q.empty())
    {
        auto t = q.top(); //当前与起始点距离最短的点
        q.pop();
        int v = t.second, d = t.first; //点和最短距离
        if (visited[v])                //如果已经更新过,就不需要再次更新
            continue;
        visited[v] = true;
        //下面为松弛操作
        for (auto &p : graph[v]) //遍历所有和该点相邻的点
        {
            //如果找到了一个点满足:当前点的最短距离加该点到当前点的权值<该点最小距离
            if (dis[v] + p.first < dis[p.second])
            {
                dis[p.second] = dis[v] + p.first;  //更新该点到起始点最小距离
                q.push({dis[p.second], p.second}); //将该点入队(入队后所有经过松弛的点会自动排序,队首就是这一次的最小距离点)
            }
        }
    }
    int maxdis = *max_element(dis.begin() + 1, dis.end()); //注意第一个0不要放进去
    return maxdis != INT_MAX ? maxdis : -1;
}

/* 
Floyed算法：
1、适用范围：无负权多源最短路径
2、主要思路：
和Dijkstra的松弛操作思路大致相同,就是两点的最短路径,可能是直接相连的路径长度，也可能是经过一个中转站的长度

3、具体实现：
维护一个二维的距离数组dis,三次循环遍历所有点,比较两点距离和所有有一个中转站的距离,找到最小的就是两点最短距离
*/

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INT_MAX / 2)); //这边除2是因为太大了会超范围
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (auto t : times)
        dis[t[0]][t[1]] = t[2];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int maxdis = *max_element(dis[k].begin() + 1, dis[k].end());
    return maxdis < INT_MAX / 2 ? maxdis : -1;
}


/* 
Bellman-Ford算法：一共n-1次,每次都对所有的边进行松弛
与Dijkstra的区别：dijkstra是每次找到最短距离的点，然后以这个点为中心向邻点进行松弛；Bellman-ford是每次都对所有边进行更新
*/
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<int> dis(n + 1, INT_MAX / 2);
    dis[k] = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(dis.begin(), dis.end()); //每次松弛dis都会变,所以要复制一份数组对之前的dis值进行优化
        for (auto t : times)
            dis[t[1]] = min(dis[t[1]], temp[t[0]] + t[2]);
    }
    int maxdis = *max_element(dis.begin() + 1, dis.end());
    return maxdis < INT_MAX / 2 ? maxdis : -1;
}