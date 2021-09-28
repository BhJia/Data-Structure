#include<bits/stdc++.h>
using namespace std;
// 矩阵中特殊问题：给定一个0/1矩阵，找到特殊1的个数，满足该行该列其它元素都是0
// 很巧妙的思路：用两个一维数组分别记录矩阵各行和各列的元素和，然后遍历矩阵，如果遇到1且该行该列和都是1，就是特殊位置
int numSpecial(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size(), res = 0;
    vector<int> row(m, 0), col(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                res++;
    return res;
}