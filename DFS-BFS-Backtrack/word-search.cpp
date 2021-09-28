#include <iostream>
#include <vector>
#include<string>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int mark[201][201] = {0};
// 判断矩阵中是否存在一条路径，包含字符串的每个字符，且不能重复走某一格
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}
//因为主函数是bool类型的判断函数，故dfs函数也是bool类型的
// index是当前匹配word中第几个字符
bool dfs(vector<vector<char>> &board, int x, int y, string word, int index)
{
    int m = board.size();
    int n = board[0].size();
    //先判断特殊情况：点在矩阵外/点走过了/点不是要匹配的字符
    if (x < 0 || y < 0 || x >= m || y >= n || mark[x][y] || board[x][y] != word[index])
        return false;
     if (index == word.size() - 1) //所有字符都匹配成功，那么存在一条路径
        return true;
    mark[x][y] = 1; //标记该点
    for (int i = 0; i < 4; i++) //朝四个方向递归//
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if (dfs(board, x1, y1, word, index + 1)) //某一个方向与下一个字符匹配成功
            return true;
    }
    mark[x][y] = 0;//撤销标记
    return false;
}