#include<bits/stdc++.h>
using namespace std;
// 句子分割问题：力扣上很多句子分割问题，就是给一个带空格的很长的句子，然后处理其中的单词


// 最后一个单词的长度：把所有单词放到数组中,返回数组尾元素长度
int lengthOfLastWord(string s)
{
    if (s.empty()) 
        return 0;
    s += " ";
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            if (!temp.empty()) //要不要判断非空取决于给定的字符串有没有前置或者后置的空格
            {
                res.push_back(temp);
                temp.clear();
            }
        }
        else
            temp += ch;
    }
    if (res.empty())
        return 0;
    return res.back().size();
}

// 557、反转字符串中的单词：给定一个字符串句子，反转每个单词并保持原顺序不变
string reverseWords(string s)
{
    if (s.empty())
        return 0;
    s += " ";
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            res.push_back(temp);
            temp.clear();
        }
        else
            temp += ch;
    }
    s.clear();
    for (string &str : res)
    {
        reverse(str.begin(), str.end());
        s += str + ' ';
    }
    s.pop_back();
    return s;
}

// 翻转字符串：给定一个有前置和后置空格的句子，翻转整体的字符串顺序，并把前置后置空格去掉
string reverseWords(string s)
{
    if (s.empty())
        return "";
    s += " ";
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            if (!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
        }
        else
            temp += ch;
    }
    s.clear();
    reverse(res.begin(), res.end());
    for (string &str : res)
        s += str + ' ';
    s.pop_back();
    return s;
}

// 1816、截断句子：把一个句子截断为只有前k个单词
// 方法：把所有单词放到数组中，然后把前K个单词重新链接
string truncateSentence(string s, int k)
{
    s += " ";  //在句子末尾加一个空格，这样最后一个单词就不会因为没有后面的空格而被遗漏
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ') //如果遇到空格就输出前面的字符串
        {
            res.push_back(temp);
            temp.clear();
        }
        else
            temp += ch;
    }
    for (int i = 0; i < k; i++)
        temp += res[i] + ' ';
    temp.pop_back();
    return temp;
}

// 字符串中的不同整数：给定一个由字母和数字组成的字符串，求所有被字母分隔的不重复的整数的个数(注意有前导0的不算，但0是可以的)
// 这道题很考验细节，基本思路很简单，就是遍历字符串遇到数字就放到临时字符串中，然后遇到字母再把临时字符串放到集合中去重
int numDifferentIntegers(string word)
{
    set<string> s;
    string temp = ""; //临时字符串
    word += 'a';  //在字符串的末尾加上一个字母，这样遍历到最后的时候如果有整数就不会被遗漏
    for (char ch : word)
    {
        if (isalpha(ch))  //遇到字母(注意不要把这个和判断非空语句写在一起，不然的话要分好几种类，现在只要分是字母和是数字两种讨论)
        {
            if (!temp.empty()) //如果遇到字母且临时字符串非空，就把它加入集合并重置临时字符串
            {
                s.insert(temp);
                temp.clear(); 
            }
        }
        else  //如果遇到数字
        {
            if (temp == "0")  //如果之前有过前导0(注意这里不是temp.back()=='0,因为前导0的前面肯定是字母,如果不是字母就不是前导0)
                temp.clear(); //清空前导0
            temp += ch;
        }
    }
    return s.size();
}

// 最常见的单词：给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。
// 题目保证至少有一个词不在禁用列表中，而且答案唯一。
// 禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
string mostCommonWord(string paragraph, vector<string> &banned)
{
    paragraph += ' ';
    string temp = "";
    map<string, int> m;   //哈希表记录单词出现频次
    set<string> ban(banned.begin(), banned.end()); //把禁用列表放到集合中方便查找
    for (char ch : paragraph) 
    {
        if (!isalpha(ch)) 
        {
            if (!temp.empty())
            {
                m[temp]++;
                temp.clear();
            }
        }
        else
            temp += tolower(ch);  //注意返回的是小写字母
    }
    vector<string> words;
    for (auto p : m)
        words.push_back(p.first);
    sort(words.begin(), words.end(), [&](string &s, string &p) { return m[s] > m[p]; }); //按照频次降序
    if (banned.empty()) //如果没有禁用单词，直接返回排序后列表首元素
        return words[0];
    for (auto w : words) //否则在禁用列表中查找，第一个没有的单词就返回
        if (ban.find(w) == ban.end())
            return w;
    return "";
}

// 824、山羊拉丁文
string toGoatLatin(string s)
{
    s += " ";
    string temp = "";
    string vowels = "aeiouAEIOU";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            res.push_back(temp);
            temp.clear();
        }
        else
            temp += ch;
    }
    s.clear();
    for (int i = 0; i < res.size(); i++)
    {
        if (vowels.find(res[i][0]) != -1)
            s += res[i];
        else
        {
            string t = res[i] + res[i][0];
            t.erase(t.begin());
            s += t;
        }
        s += "ma";
        s.insert(s.size(), i + 1, 'a');
        s += ' ';
    }
    s.pop_back();
    return s;
}

// 检查单词是否为句中其他单词前缀：给定句子和一个单词，在句子中的所有单词中查找其是否为某个单词前缀，返回该单词索引(从1开始)
int isPrefixOfWord(string s, string searchWord)
{
    s += " ";
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            res.push_back(temp);
            temp.clear();
        }
        else
            temp += ch;
    }
    for (int i = 0; i < res.size(); i++)
        if (res[i].find(searchWord) == 0)
            return i + 1;
    return -1;
}



// 重新排列单词间的空格
string reorderSpaces(string s)
{
    s += " ";
    string temp = "";
    vector<string> res;
    int cnt = -1;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            cnt++;
            if (!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
        }
        else
            temp += ch;
    }
    int n = res.size();
    s.clear();
    if (n == 1)  //注意一个单词要单独考虑
    {
        s += res[0];
        s.insert(s.size(), cnt, ' ');
        return s;
    }
    int blank = cnt / (n - 1), remain = cnt - blank * (n - 1);
    for (int i = 0; i < res.size() - 1; i++)
    {
        s += res[i];
        s.insert(s.size(), blank, ' ');
    }
    s += res.back();
    if (remain > 0)
        s.insert(s.size(), remain, ' ');
    return s;
}

// 1859、将句子排序：句子中的每个单词最后都有一个数字，按照数字给单词排序
string sortSentence(string s)
{
    s += " ";
    string temp = "";
    vector<string> res;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            res.push_back(temp);
            temp.clear();
        }
        else
            temp += ch;
    }
    s.clear();
    sort(res.begin(), res.end(), [&](string &a, string &b) { return a.back() < b.back(); });
    for (auto &str : res)
    {
        str.pop_back();
        s += str + ' ';
    }
    s.pop_back();
    return s;
}