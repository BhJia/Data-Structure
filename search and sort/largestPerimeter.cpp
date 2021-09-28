#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//给定数组作为三角形的边长,求三角形最大周长、
//思路：降序排序后不断用三个连续指针从头开始遍历直到找到可以围成的三角形
int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums[i] < nums[i + 1] + nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2];
    }
    return 0;
}