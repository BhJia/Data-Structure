#include <iostream>
#include <vector>
#include<set>
#include<string>
#include <algorithm>
using namespace std;
// 词典中最长单词：给出一个词典，找出一个单词由词典其它单词不断加一个字母得到
// 方法：遍历字符串数组找出一个字符串所有前缀均在数组中
// STL语法补充：1、集合set的初始化可由vector拷贝构造得到  2、字符串可直接用><号比较,不需要调用compare函数
string longestWord(vector<string> &words)
{
    string ans;
    set<string> s(words.begin(), words.end()); //建立集合存放数组所有字符串
    for (auto i : words)
    {
        bool flag = true;
        for (int j = 0; j < i.size() - 1; ++j)
        {
            if (!s.count(i.substr(0, j + 1))) //判断前缀是否在集合中
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            if (ans.empty() || i.size() > ans.size() || i.size() == ans.size() && i < ans)
                ans = i;
        }
    }
    return ans;
}

void inputArr(vector<string> &arr)
{
    string x;
    while (cin >> x) 
    {
        arr.push_back(x);
        if (cin.get() == '\n')
            break;
    }
}

int main()
{
    vector<string> arr;
    inputArr(arr);
    string s = longestWord(arr);
    cout << s;
    return 0;
}