#include<bits/stdc++.h>
using namespace std;
// 最小操作数：给定n个元素的数组，每次让n-1个元素+1，返回所有元素相等的最小操作数
// 思路：逆向思维，将n-1个元素+1相当于把另外的1个元素-1,那么不断操作剩下的一定是最小元素,所以只要求所有元素减去最小元素的和
int minMoves(vector<int> &nums)
{
    int minnum = *min_element(nums.begin(), nums.end());
    int step = 0;
    for (int num : nums)
        step += num - minnum;
    return step;
}