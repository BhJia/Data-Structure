#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
//同构字符串:指字符串字符一一映射
// 第一个出现的映射关系就是该字母的映射关系，所以用find 函数查找第一个出现字符串的位置，如果不一样就不是同构
bool isIsomorphic(string s, string t)
{
    for (int i = 0; i < s.size(); i++)
        if (s.find(s[i]) != t.find(t[i]))
            return false;
    return true;
}