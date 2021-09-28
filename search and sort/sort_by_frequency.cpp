#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// 将给定数组按照数组出现频率升序,如果相同就按照大小降序
// 典型哈希表+自定义排序 
//代码很简洁！这就是简洁美！
vector<int> frequencySort(vector<int> &nums)
{
    map<int, int> map;
    for (auto x : nums)
        map[x]++;
    sort(nums.begin(), nums.end(), [&](int i, int j) { return map[i] < map[j] || (map[i] == map[j] && i > j); });
    return nums;
}

