#include<bits/stdc++.h>
using namespace std;
// 输入字符串，反转字符串里的元音字母
// 双指针遍历，不断向中间移动直到找到元音，然后交换即可
string reverseVowels(string s)
{
    string temp = "aeiouAEIOU";
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        while (temp.find(s[l]) == -1 && l < r)
            l++;
        while (temp.find(s[r]) == -1 && l < r)
            r--;
        if (l < r)
            swap(s[l++], s[r--]);
    }
    return s;
}