#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int>& res,int k,int i)
{
    //数组中任意数和为K:转化为0/1背包问题,即每个数可选可不选
    if(i==res.size()) //结束条件
        return res[i]==k;
    return dfs(res, k, i + 1) || dfs(res, k - res[i], i + 1); //两种情况只要有一种满足就成立
}

int main()
{
    int k, n;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    cin >> k;
    if (dfs(res,k,0))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}