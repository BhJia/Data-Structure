#include <iostream>
#include <vector>
using namespace std;
bool isvalid(int row, int col, int n, vector<string> chessboard);
vector<vector<string>> SolutionBoard;
void DFS(int row, int n, vector<string> &chessboard)
{
    if (row == n)
    {
        SolutionBoard.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) 
    {
        if (isvalid(row, col, n,chessboard))
        {
            chessboard[row][col] = 'Q';
            DFS(row + 1, n,chessboard);
            chessboard[row][col] = '.';
        }
    }
}

bool isvalid(int row, int col, int n, vector<string> chessboard)
{
    int count = 0;
    // 检查列//
    for (int i = 0; i < row; i++)
    {
        if (chessboard[i][col] == 'Q')
        {
            return false;
        }
    }
    // 检查 45度角是否有皇后//
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }
    // 检查 135度角是否有皇后//
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
