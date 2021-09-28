#include<bits/stdc++.h>
using namespace std;
//求两个集合交集：把两个数组分别放到集合中去重,然后遍历基数小的集合看元素在另一个集合是否存在
//利用set 中count函数可以降低时间复杂度,但set的引入避免不了空间复杂度提升
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    set<int> s1, s2;
    for (int i = 0; i < nums1.size(); i++)
    {
        s1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        s2.insert(nums2[i]);
    }
    if (s1.size() < s2.size())
    {
        for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        {
            if (s2.count(*it))
                res.push_back(*it);
        }
    }
    else
    {
        for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
        {
            if (s1.count(*it))
                res.push_back(*it);
        }
    }
    return res;
}
// 方法2：哈希表记录集合1的元素个数，遍历集合2查找是否在表1中
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    map<int, int> m;
    for (auto i : nums1)
        m[i]++;
    for (auto i : nums2)
        if (m[i] > 0 && find(res.begin(), res.end(), i) == res.end())
            res.push_back(i);
    return res;
}

//数组交集2:不去重，重复元素在交集中出现次数取其在两数组中出现最少次数
//排序+双指针：先排序，然后双指针同时移动,比较两数组指针指向的元素
//如果一样就加入集合，同时移动；如果不一样，哪边小哪边指针移动;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int index1 = 0, index2 = 0;
    vector<int> res;
    while (index1 < nums1.size() && index2 < nums2.size())
    {
        if (nums1[index1] < nums2[index2])
            index1++;
        else if (nums2[index2] < nums1[index1])
            index2++;
        else
        {
            res.push_back(nums1[index1]);
            index1++;
            index2++;
        }
    }
    return res;
}

// 方法2：哈希表(两个哈希表都是后面重做之后想出来的)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    map<int, int> m;
    for (auto i : nums1)
        m[i]++;
    for (auto i : nums2)
        if (m[i] > 0)
        {
            res.push_back(i);
            m[i]--;
        }
    return res;
}