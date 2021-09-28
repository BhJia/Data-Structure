#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
// 验证外星语词典：给定一个单词组和一个新的词典,判断单词组是否按照新字典序排序
// 思路：按照新字典序自定义排序，比较排序后排序前是否相等；
bool isAlienSorted(vector<string> &words, string order)
{
    vector<string> w = words;
    sort(words.begin(), words.end(), [&](string &a, string &b) {
        int len = min(a.size(), b.size());   //求出a.b较小长度
        for (int i = 0; i < len; i++)    
        {
            if (order.find(a[i]) > order.find(b[i]))  //从左到右一一比较每个字符在新字典中的位置
                return false;
            if (order.find(a[i]) < order.find(b[i]))
                return true;
        }
        return len == a.size(); //如果前面没比较出来说明两个单词在前面一模一样,那较短的单词排在前面
    });
    return w == words;
}