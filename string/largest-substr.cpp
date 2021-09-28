#include<bits/stdc++.h>
using namespace std;
// 两个相同字符之间的最长子串：给定一个字符串，找出任意两个相同字符之间子串的最大长度
// 思路：遍历字符串，从右边找第一个相同的字符
// STL语法补充：string 中 find/rfind/find_first_of/find_last_of 返回的均是查找到的位置下标而非迭代器
// 但set中find是迭代器，*find是元素的值，用distance函数才能求出下标位置
int maxLengthBetweenEqualCharacters(string s)
{
    int res = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int len = 0;
        if (s.rfind(s[i]) != -1)    //这里用s.find_last_of也可以
            len = s.rfind(s[i]) - i - 1;
        res = max(res, len);
    }
    return res;
}
