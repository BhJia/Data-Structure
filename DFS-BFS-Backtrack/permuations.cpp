#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
//全排列：典型回溯算法框架
//注意：只有排列问题才需要mark数组标记访问，因为全排列每个数都要选择
vector<vector<int>> res;
vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> path;
    vector<int> mark(n, 0);
    dfs(res, path, mark, nums);
    return res;
}
void dfs(vector<vector<int>> &res, vector<int> &re, vector<int> &mark, vector<int> &nums)
{
    if (re.size() == nums.size())
    {
        res.push_back(re);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            re.push_back(nums[i]);
            dfs(res, re, mark, nums);
            re.pop_back();
            mark[i] = 0;
        }
    }
}

//全排列(有重复)
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> re;
    vector<int> mark(n, 0);
    dfs(res, re, mark, nums);
    return res;
}

void dfs(vector<int> &path, vector<int> &mark, vector<int> &nums)
{
    if (path.size() == nums.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        //剪枝:1、该元素已选择  2、该元素和上一个重复并且上一个选择过(注意:必须是建立在数组已排序的前提上)
        if (mark[i] || (i > 0 && nums[i] == nums[i - 1] && mark[i - 1])) 
            continue;
        mark[i] = 1;
        path.push_back(nums[i]);
        dfs(res, path, mark, nums);
        path.pop_back();
        mark[i] = 0;
    }
}



//字符串全排列(无重复)
vector<string> res1;
vector<string> permutation(string S)
{
    if (S.size() == 0)
        return res1;
    string path;
    vector<bool> mark(S.size());
    backtrack(path, mark, S);
    return res1;
}
void backtrack(string path, vector<bool> &mark, string S)
{
    if (path.size() == S.size())
    {
        res1.push_back(path);
        return;
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (!mark[i])
        {
            mark[i] = true;
            path.push_back(S[i]);
            backtrack(path, mark, S);
            path.pop_back();
            mark[i] = false;
        }
    }
}

//字符串全排列(有重复)
vector<string> res2;
vector<string> permutation(string S)
{
    if (S.size() == 0)
        return res2;
    string path;
    sort(S.begin(), S.end());
    vector<bool> mark(S.size());
    backtrack(path, mark, S);
    return res2;
}
void backtrack(string path, vector<bool> &mark, string S)
{
    if (path.size() == S.size())
    {
        res2.push_back(path);
        return;
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (!mark[i])
        {
            if (i > 0 && S[i] == S[i - 1] && mark[i - 1])
                continue;
            mark[i] = true;
            path.push_back(S[i]);
            backtrack(path, mark, S);
            path.pop_back();
            mark[i] = false;
        }
    }
}