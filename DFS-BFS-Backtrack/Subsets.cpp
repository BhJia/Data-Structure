#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
    回溯问题解题步骤：
    1、画出递归树，找到状态变量，即回溯函数的参数
    2、确定结束条件
    3、找到选择列表(与状态变量有关)
    4、判断是否需要剪枝
    5、在选择列表里作出选择
    6、递归进入下一层
    7、撤销选择 
 */
// 子集1(无重复元素)
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> path;
    backtrack(nums, path, 0);
    return res;
}
void backtrack(vector<int> nums, vector<int> &path, int start)
{
    res.push_back(path); //所有路径都应该加入最终结果,没有结束条件
    for (int i = start; i < nums.size(); i++) //start是状态变量,是当前选择列表的起始位置
    {
        path.push_back(nums[i]);   //做出选择
        backtrack(nums, path, i + 1);  //更新状态变量并进入下一个选择列表
        path.pop_back(); //撤销选择
    }
}

//子集2(有重复元素)
vector<vector<int>> res1;
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> path;
    sort(nums.begin(), nums.end());
    backtrack(nums, path, 0);
    return res1;
}

void backtrack(vector<int> nums, vector<int> &path, int start)
{
    res1.push_back(path);
    for (int i = start; i < nums.size(); i++)
    {
        if (i > start && nums[i] == nums[i - 1]) //剪枝：如果该选择列表与上一个选择列表重复就跳过本次选择
            continue;
        path.push_back(nums[i]);
        backtrack(nums, path, i + 1);
        path.pop_back();
    }
}