#include<bits/stdc++.h>
using namespace std;
// 给定一个由0/1组成的矩阵，返回其中最弱的k行的下标
// 比较两行i,j优先看1的数量，1的数量相同看下标大小
// 典型的自定义排序，只不过这里按照下标重新定义数组，对下标进行排序
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<int> res;
    int m = mat.size();
    for (int i = 0; i < m; i++)
        res.push_back(i);
    sort(res.begin(), res.end(), [&](int &a, int &b) { return mat[a] == mat[b] ? a < b : mat[a] < mat[b]; });
    return vector<int>(res.begin(), res.begin() + k);
}