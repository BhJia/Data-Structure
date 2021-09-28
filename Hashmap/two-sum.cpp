#include<bits/stdc++.h>
using namespace std;
/*
    用哈希表解决Leetcode上两数之和的问题：
    哈希表的每一个Key值都对应着一个value
    本题把给定数组的元素看成key,元素下标看成value,
    开始哈希表为空,然后遍历数组每个元素nums[i],
    对于每个nums[i],在表中查找有无对应的key值target-nums[i],
    如果有,则输出对应的value值(即下标)；
    如果没有，则将nums[i]与i作为Key与value值存入表中
    注意：hashmap的STL容器为unordered_map，
    其与map的区别是不需要排序

*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashmap;   //建立一个空的哈希表//
        for (int i = 0; i < nums.size();i++)//对给定数组进行遍历//
        {
            unordered_map<int, int>::iterator key = hashmap.find(target - nums[i]);//在hashmap中查找需要的key值//
            if(key!=hashmap.end())         //如果表中存在要找的值的key值//
            {
                return {(*key).second, i}; //输出value值//
            }
            hashmap[nums[i]] = i;          //否则将key和value存入表中//
        }
        return {};                         //如果遍历完成没有查找到，输出空//
    }
};


// 隔了一段时间自己做了然后又写了一个
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (m.count(target - numbers[i]))
        {
            res.push_back(i + 1);
            res.push_back(m[target - numbers[i]]);
            if (res[0] > res[1])
                swap(res[0], res[1]);
            return res;
        }
        m[numbers[i]] = i + 1;
    }
    return res;
}