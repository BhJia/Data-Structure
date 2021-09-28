#include<bits/stdc++.h>
using namespace std;
// 重复子串：判断s是否由一个子串重复多次构成
// 思路：思路比较奇怪，就是如果满足题意，那么把两个s连起来并去掉首尾剩下的字符串一定包含s
// STL语法补充：字符串末尾添加可以直接用'+'; find(s,1)表示从下表为1的位置开始查找
bool repeatedSubstringPattern(string s)
{
    return (s + s).find(s, 1) != s.size();
}