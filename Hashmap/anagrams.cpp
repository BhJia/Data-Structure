#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//找到s中所有p的字母异位词子串
// 方法1：多好的方法，可惜超时了!!!气死
bool isAnagram(string a, string b) //判断a和b互为字母异位词
{
    if (a.size() != b.size())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a==b; 
}
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int k = p.size();
    if (s.size() < k)  //特殊情况
        return res;
    for (int i = 0; i < s.size() - k + 1; i++) //不断抽取与p长度相等的子串,判断是否为p的字母异位词
    {
        if (isAnagram(s.substr(i, k), p))
            res.push_back(i);
    }
    return res;
}

// 方法2：哈希滑动窗口
// 用数组滑动窗口作为哈希表的功能，向右滑动的同时比较
vector<int> findAnagrams1(string s, string p)
{
    vector<int> res;
    if (p.size() > s.size()) 
        return res;
    vector<int> map(128);
    vector<int> windows(128); //用数组哈希表构建滑动窗口
    for (char a : p) //用数组哈希表统计p中字符出现的次数
        map[a - 'a']++;
    for (int i = 0; i < p.size() - 1; i++) //滑动窗口初始化
        windows[s[i] - 'a']++;
    int l = 0, r = p.size() - 1; //窗口是[l,r]
    while (r < s.size())
    {
        windows[s[r++] - 'a']++;
        if (windows == map)  //vector相等可直接比较
            res.push_back(l);
        windows[s[l++] - 'a']--;
    }
    return res;
}

// 异位词组合：给定字符串组，找到所有异位词组合
// 没错，方法1又超时了，气不气，101个测试案例过了100个
bool isAnagram(string a, string b) //判断a和b互为字母异位词
{
    if (a.size() != b.size())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    vector<bool> used(strs.size(), false);
    for (int i = 0; i < strs.size(); i++)
    {
        vector<string> temp;
        if (used[i])
            continue;
        temp.push_back(strs[i]);
        used[i] = true;
        for (int j = i + 1; j < strs.size(); j++)
        {
            if (isAnagram(strs[i], strs[j]) && !used[j])
            {
                temp.push_back(strs[j]);
                used[j] = true;
            }
        }
        res.push_back(temp);
    }
    return res;
}

// 方法2：(很简洁)遍历字符数组的时候对每个字符单独排序,并把排序后结果相同的字符映射到同一个哈希集合中
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    map<string, vector<string>> m; //哈希表从排序后的单词映射到异位词组合
    for (auto i : strs)
    {
        string s = i;
        sort(s.begin(), s.end());
        m[s].push_back(i);
    }
    for (auto p : m)  //遍历哈希表把每个异位词组合输出
        res.push_back(p.second);
    return res;
}

int main()
{
    string s, p;
    cin >> s >> p;
    vector<int> res = findAnagrams1(s, p);
    for(auto i:res)
        cout << i << " ";
    return 0;
}