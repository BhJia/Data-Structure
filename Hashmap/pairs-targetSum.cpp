#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 数对和:给定一个数组,求和为指定和的数对(一个数只能用一次)
vector<vector<int>> pairSums(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    map<int, int> m; //哈希表记录数值到出现次数的映射
    for (auto i : nums) 
    {
        if (m.count(target - i) && m[target - i] >= 1) //为了避免重复使用，使用完后次数-1
        {
            res.push_back(vector<int>{i, target - i});
            m[target - i]--;
        }
        else
            m[i]++;
    }
    return res;
}