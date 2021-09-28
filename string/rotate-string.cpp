#include<bits/stdc++.h>
using namespace std;
// 旋转字符串：给定两个字符串，判断A是否可以通过旋转操作得到B
// 旋转操作：将A的第一个字符移动到最后一个
// 思路：首先判断A,B长度是否相等，然后将两个A首尾相连，判断B在不在这个长字符串中
// 因为两个A首尾相连包含了所有旋转的情况
// 注意两个字符串相加是可以直接得到一个新字符串的
bool rotateString(string s, string t)
{
    return s.size() == t.size() && (s + s).find(t) != -1;
}