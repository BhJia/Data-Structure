#include<bits/stdc++.h>
using namespace std;
// 检查数组是否经过旋转可以变成排序数组
// 开始想的是类比旋转字符串那道题，判断两个数组相连是否存在排序后数组，但是太复杂了
// 思路：把数组看成一个环,判断是否之多只有一个递减的位置
bool check(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] > nums[(i + 1) % nums.size()])
            count++;
    return count <= 1;
}