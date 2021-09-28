#include<bits/stdc++.h>
using namespace std;
// 回文子串个数
int countSubstrings(string s)
{
    int n = s.size();
    if (s.empty())
        return 0;
    int res = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false)); //dp[i][j]代表下标从i到j的子串是否回文
    for (int i = n - 1; i >= 0; i--)  //注意：i要反向遍历,因为下面会出现dp[i+1][j-1]
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)           //一个字符必定回文
                dp[i][j] = true;
            else if (j == i + 1) //两个字符只要判断它们是否相等
                dp[i][j] = s[i] == s[j];
            else                  //三个及以上看s[i]和s[j]是否相等且去掉头尾的子串是否回文
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            res += dp[i][j] ? 1 : 0;
        }
    }
    return res;
}


// 验证回文串：判断一个带特殊字符的字符串中字母和数字组成的字符串是否是回文字符串
// c++ 字符串API语法补充：
// 1、isalpha():判断字符串是否为字母 2、isdigit():判断字符是否为数字  3、isalnum():判断字符串是否为字母或数字
// 3、islower()/isupper():判断字符串是否为小写字母/大写字母   4、tolower()/toupper():将字符变成小写/大写字母
bool isPalindrome(string s)
{
    string ans;
    for (char ch : s)
        if (isalnum(ch))   //如果是字母或者数字
            ans.push_back(tolower(ch));  //把字母(大写要转为小写)和数字放到ans中
    string tmp(ans.rbegin(), ans.rend()); //拷贝构造一个临时字符串作为ans的反转字符串
    return tmp == ans;  //判断ans正向遍历与反向遍历是否相等,来确定是否回文
}
