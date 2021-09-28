#include<bits/stdc++.h>
using namespace std;
// 仅仅反转字母：保持其他字符相对位置不变，仅仅反转字母
string reverseOnlyLetters(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        while (l < r && !isalpha(s[l]))
            l++;
        while (l < r && !isalpha(s[r]))
            r--;
        if (l < r)
            swap(s[l++], s[r--]); //注意这里l,r也要增减，否则会死循环
    }
    return s;
}