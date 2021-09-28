#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
// 两个数组，arr1 和 arr2，arr2 中的元素各不相同,每个元素都出现在 arr1 中
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
// 未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> m;
    set<int> s;
    vector<int> res;
    sort(arr1.begin(), arr1.end());      //对arr1排序
    for (int i = 0; i < arr1.size(); i++)//用哈希表统计arr1中每个元素出现的频率
    {
        if (!m.count(arr1[i]))
            m[arr1[i]] = 1;
        else
            m[arr1[i]]++;
    }
    for (int i = 0; i < arr2.size(); i++)  //把arr2中的元素放到集合中,并根据哈希表的次数输出arr1中元素
    {

        s.insert(arr2[i]);
        for (int j = 0; j < m[arr2[i]]; j++)
        {
            res.push_back(arr2[i]);
        }
    }
    for (int i = 0; i < arr1.size(); i++) //重新遍历arr1，把没有在arr2中出现的元素放到末尾
    {
        if (!s.count(arr1[i]))
            res.push_back(arr1[i]);
    }
    return res;
}