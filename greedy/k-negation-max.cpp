#include<bits/stdc++.h>
using namespace std;
// K次取反后最大的数组：给定一个数组,每次随机选择一个元素进行取反,求K次取反后最大和
// 贪心：每次都排序取最小的
int largestSumAfterKNegations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    while (k)
    {
        nums[0] *= -1;
        sort(nums.begin(), nums.end());
        k--;
    }
    return accumulate(nums.begin(), nums.end(), 0);
}