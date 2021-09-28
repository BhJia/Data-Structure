#include<bits/stdc++.h>
using namespace std;
// 重新组合字符串：给你一个混合了数字和字母的字符串 s，将该字符串重新格式化，使得任意两个相邻字符的类型都不同
string reformat(string s)
{
    string a = "", b = "", res = "";
    for (char ch : s)
        isalpha(ch) ? a += ch : b += ch;
    int l = a.size() - b.size();
    if (abs(l) > 1)
        return "";
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++)
    {
        res += a[i];
        res += b[i];
    }
    if (a.size() == b.size())
        return res;
    else if (a.size() == len)
        res.insert(res.begin(), b.back());
    else
        res += a.back();
    return res;
}