#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
    //暴力解法，单独考虑每个柱子，对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。
    int n = height.size();
    int sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftmax = 0;
        int rightmax = 0;
        for (int j = 0; j < i; j++)
        {
            leftmax = max(leftmax, height[j]);
        }
        for (int k = i + 1; k < n; k++)
        {
            rightmax = max(rightmax, height[k]);
        }
        sum += max(0, min(leftmax, rightmax) - height[i]);
    }
    return sum;
}