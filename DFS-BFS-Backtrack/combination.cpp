#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> res;
//返回从1到n的n个数中取K个数的组合
vector<vector<int>> combine(int n, int k)
{
    vector<int> path;
    backtrack(n, k, 1, path); 
    return res;
}
void backtrack(int n, int k, int start, vector<int> &path)
{
    if (path.size() == k)   //结束条件:path中有k个数
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++) //状态变量start决定选择列表从哪里开始
    {
        path.push_back(i);
        backtrack(n, k, i + 1, path); //不能重复取，所以递归的时候要从下一个数开始
        path.pop_back();
    }
}

//可以重复的组合总和:从给定数组中任选一些数，使和为目标和
vector<vector<int>> res1;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> path;
    backtrack(candidates, path, 0, 0, target);
    return res1;
}
void backtrack(vector<int> &candidates, vector<int> &path, int start, int sum, int target)
{
    if (sum == target) 
    {
        res1.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) //状态变量为sum和start
    {
        if (sum > target)
            continue;
        path.push_back(candidates[i]);
        backtrack(candidates, path, i, sum+candidates[i], target);//可以重复，所以递归的时候可以当前数继续
        path.pop_back();
    }
}

// 组合总和不能重复
vector<vector<int>> res2;
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, path, 0, 0, target);
    return res2;
}
void backtrack(vector<int> &candidates, vector<int> &path, int start, int sum, int target)
{
    if (sum == target)
    {
        res2.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (sum > target || (i > start && candidates[i] == candidates[i - 1])) //剪枝
            continue;
        path.push_back(candidates[i]);
        backtrack(candidates, path, i + 1, sum+candidates[i], target);
        path.pop_back();
    }
}

vector<vector<int>> res3;
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> path;
    backtrack(k, n, 0, path, 1);
    return res3;
}

void backtrack(int k, int n, int sum, vector<int> &path, int start)
{
    if (path.size() == k && sum == n)
    {
        res3.push_back(path);
        return;
    }
    for (int i = start; i <= 9; i++)
    {
        if (sum > n || path.size() > k)
            continue;
        path.push_back(i);
        backtrack(k, n, sum + i, path, i + 1);
        path.pop_back();
    }
}

vector<int> path1;
int count1=0;
int combinationSum4(vector<int> &nums, int target)
{
    backtrack(nums, 0, target);
    return count1;
}
void backtrack(vector<int> &nums, int sum, int target)
{
    if (sum == target)
    {
        count1++;
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum > target)
            return;
        path1.push_back(nums[i]);
        backtrack(nums, sum + nums[i], target);
        path1.pop_back();
    }
}