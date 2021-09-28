#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 查找常用字符：给定一个字单词数组，找到每个单词中都出现的字符，并输出最小次数
// 方法：双哈希表，第一个局部哈希表存储每个单词字符出现次数，第二个全局哈希表存储所有字符出现最小次数
// 注意该题也是用数组代替哈希表
vector<string> commonChars(vector<string> &A)
{
    vector<string> res;
    vector<int> minfreq(26, INT_MAX);
    for (auto word : A)   
    {
        vector<int> freq(26, 0);
        for (auto ch : word)    //局部哈希表记录每个单词字符次数
            freq[ch - 'a']++;
        for (int i = 0; i < 26; i++)//遍历局部哈希表的每个字符,更新最小出现次数
            minfreq[i] = min(minfreq[i], freq[i]);
    }
    for (int i = 0; i < 26; i++) 
    {
        string s(1, 'a' + i);         //char类型转string类型
        for (int j = 0; j < minfreq[i]; j++) 
            res.push_back(s);
    }
    return res;
}