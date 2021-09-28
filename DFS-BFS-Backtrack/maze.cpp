#include <iostream>
#include <vector>
using namespace std;
//迷宫地图: 最外面一圈是边界，里面1代表有障碍不能走，0可以走//
int Map[10][10] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
//一个坐标类//
class Point
{
public:
    int m_x;
    int m_y;
    Point(int x, int y) : m_x(x), m_y(y){};
};

int detx = 8, dety = 8;                             //目的地的坐标//
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; //四个方向//
int mark[10][10] = {0};                             //用来记录已经走过的路(0未走过，1走过)//
vector<vector<Point>> SolutionMaze;                 //所有正确路径的解集//
vector<Point> path;                                 //一个正确路径//
void DFS(int x, int y)                              //当前坐标//
{
    Point p(x, y);
    if (x == detx && y == dety) //递归结束条件//
    {
        path.push_back(p);
        SolutionMaze.push_back(path);
        path.pop_back();
        return;
    }
    mark[x][y] = 1;
    path.push_back(p);
    for (int i = 0; i < 4; i++) //朝四个方向递归//
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if (Map[x1][y1] == 0 && mark[x1][y1] == 0)
        {
            DFS(x1, y1);
        }
    }
    mark[x][y] = 0;
    path.pop_back();
}

void PrintMaze(vector<vector<Point>> &SolutionMaze)
{
    for (vector<vector<Point>>::iterator it = SolutionMaze.begin(); it != SolutionMaze.end(); it++)
    {
        for (vector<Point>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << "(" << (*vit).m_x << "," << (*vit).m_y << ")"<< " ";
        }
        cout << endl;
    }
}

int main()
{
    DFS(1, 1);
    PrintMaze(SolutionMaze);
    return 0;
}