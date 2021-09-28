#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 最长回文子串的长度：经典题目,给定一个字符串，选择一些字符组成新串，求最长回文串的长度
//我的解法:哈希表记录字符频率，将字符不重复地放入数组，按频率降序排序
// 要使构造的新串是回文串，首先所有频率为偶数的字符都可以选择，频率为奇数的只能选择一次，放在中心点
int longestPalindrome(string s)
{
    int len = 0;   //子串长度
    bool hasOdd = false;  //判断是否出现频率为奇数的字符串
    if (s.empty())  //s是空串
        return 0;
    map<char, int> m; //存储每个字符出现频率
    for (char x : s)
        m[x]++;
    vector<char> res; //不重复地存储字符
    for (auto x = m.begin(); x != m.end(); x++)
    {
        res.push_back(x->first);
    }
    sort(res.begin(), res.end(), [&](char &a, char &b) { return m[a] > m[b]; });
    for (int i = 0; i < res.size(); i++)
    {
        if (m[res[i]] % 2 != 0) //出现奇数频率字符
            hasOdd = true;
        len += m[res[i]] % 2 == 0 ? m[res[i]] : (m[res[i]] - 1); //偶数直接加，奇数-1后加
    }
    return hasOdd ? len + 1 : len; //如果出现奇数,只能选择一次+1
}

//官方题解：体会代码简洁美！
int longestPalindrome1(string s)
{
    map<char, int> count;
    int ans = 0;
    for (char c : s)
        ++count[c];
    for (auto p : count) //直接遍历哈希表
    {
        int v = p.second;
        ans += v / 2 * 2; //与我的代码中偶数奇数分类的思想一致，但更简洁
        if (v % 2 == 1 && ans % 2 == 0)
            ++ans; //如果没出现奇数频率，长度就是偶数;一旦第一次出现奇数,加到长度上长度就变成奇数，之后不会触发这行代码
    }
    return ans;
}

// 回文排列：判断给定字符串能否重排成为回文串
// 思路：哈希记录次数,奇数次数最多只能出现一次
bool canPermutePalindrome(string s)
{
    map<char, int> m;
    bool flag = false;
    for (auto i : s)
        m[i]++;
    for (auto i : m)
    {
        if (flag && i.second % 2 != 0)
            return false;
        if (i.second % 2 != 0)
            flag = true;
    }
    return true;
}
