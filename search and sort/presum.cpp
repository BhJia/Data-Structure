#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// 前缀和：
int pivotIndex(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int leftsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (leftsum == sum - nums[i] - leftsum)
            return i;
        leftsum += nums[i];
    }
    return -1;
}