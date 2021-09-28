#include <bits/stdc++.h>
using namespace std;
// 给定字符串，如果不超过一个‘A’，且不超过两个连续的‘L’，则返回true;
bool checkRecord(string s)
{
    return (s.find("LLL") == -1) && (s.find('A') == s.rfind('A'));
}

bool checkRecord1(string s)
{
    return s.find("LLL") == -1 && count(s.begin(), s.end(), 'A') < 2;
}