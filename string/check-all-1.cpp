#include<bits/stdc++.h>
using namespace std;
// 检查所有的1相隔K个：给定一个由0/1组成的数组，判断是否所有相邻的1都至少间隔k个数
// 方法1：把数组转换为字符串，暴力遍历判断，但是超时
bool kLengthApart(vector<int> &nums, int k)
{
    string s = "";
    for (auto i : nums)
        s += to_string(i);
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == '1' && s.substr(i + 1, n - i - 1).find('1') < k)
            return false;
    return true;
}

// 方法2：遍历数组，用pre记录上一个1的下标，然后不断更新pre
bool kLengthApart(vector<int> &nums, int k)
{
    int pre = -k - 1; //注意初始值设置为-k-1防止第一次判断出错
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (i - pre - 1 < k)
                return false;
            pre = i;
        }
    }
    return true;
}