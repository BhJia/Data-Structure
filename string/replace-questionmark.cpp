#include<bits/stdc++.h>
using namespace std;
// 替换问号：把字符串所有问号替换成字母，使字符串没有两个连续的重复字符
// 思路：先把所有问号替换成'a',再看相邻字母是否重复
string modifyString(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            s[i] = 'a';
        while ((i > 0 && s[i] == s[i - 1]) || (i < s.size() - 1 && s[i] == s[i + 1]))
            s[i]++;
    }
    return s;
}