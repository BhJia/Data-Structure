#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
// 这些都是与删除字符串有关的,string类型本身就是一个栈，支持back(),pop_back(),push_back()等操作
string removeDuplicates(string S) //删除重复字符
{
    //删除相邻重复字符：当栈不为空且字符串元素等于栈顶元素时出栈，否则入栈
    string s;
    for (char ch:S)
    {
        if (!s.empty() && s.back() == ch)
            s.pop_back();
        else
            s.push_back(ch);
    }
    return s;
}

//删掉k位数字使剩下数字最小(这是一道很吃细节的题目,有前导0、没删完的坑)
//思路：尽量使高位的数字小，即使整个字符串呈现递增的趋势。仿照next-greater-element使用单调递增栈
string removeKdigits(string num, int k)
{
    if (num.size() == k) //如果删除字符的个数等于总字符个数返回0
        return "0";
    string s;
    int count = 0;      //记录已经删掉字符的个数
    for (char ch : num) //遍历字符串
    {
        while ((ch - '0') < (s.back() - '0')) //当前字符比栈顶字符小
        {
            if (count == k) //已经删完，跳出循环
                break;
            s.pop_back(); //删掉栈顶字符(删掉高位较大的字符)
            count++;      //继续循环，直到没有高位较大字符(字符串已经递增)或者达到删除个数K
        }
        if (s.empty() && ch == '0') //不要让前导0入栈
        {
            continue;
        }
        s.push_back(ch);
    }
    //如果遍历后并没有删除完成(因为整个字符串呈现的递增趋势较大，高位较大的字符串偏少)
    //那么此时字符串一定单调递增，只需要在尾部删除剩下的即可
    if (count < k)
    {
        for (int i = 0; i < k - count; i++)
        {
            s.pop_back();
        }
    }
    if (s.empty()) //删完后是空的，返回0
        return "0";
    return s;
}

string removeDuplicateLetters(string s)
{
    //去除重复字符并返回字典序最小的字符串
    //整体思路：使字符串单调递增；方法：单调递增栈(字符串栈)
    string str;
    map<char, int> m;
    for (char ch : s)   //用哈希表统计每个字符出现次数
        m[ch]++;
    for (char ch : s) //遍历字符串
    {
        //如果栈中存在该字符,结束本次循环,进入下一层循环并更新该字符出现次数
        if (str.find(ch) != -1)
        {
            m[ch]--;
            continue;
        }
        //如果碰到单调递减的字符,并且栈顶字符是重复字符
        while (ch < str.back() && m[str.back()] > 1)
        {
            m[str.back()]--; //删除栈顶字符并更新其出现次数
            str.pop_back();
        }
        str.push_back(ch); //否则将该字符入栈，构造单调递增栈
    }
    return str;
}

string makeGood(string s)
{
    //删除相邻的大小写字母
    string str;
    if (s.size() == 0) //判断空字符串
        return str;
    for (char ch : s)
    {
        //因为只要相邻大小写字母相同就会被一起删除所以每次循环只会删除一次，不用while
        if (!str.empty() && (ch + 32 == str.back() || ch - 32 == str.back())) //相同的大小写字母之间的ASCII码相差32
        {
            str.pop_back();
        }
        else
        {
            str.push_back(ch);
        }
    }
    return str;
}

//比较含退格的字符串
bool backspaceCompare(string S, string T)
{
    return buildstr(S) == buildstr(T);
}
string buildstr(string S)
{
    string s;
    for (char ch : S)
    {
        if (ch != '#')
        {
            s.push_back(ch);
        }
        else if (!s.empty())
        {
            s.pop_back();
        }
    }
    return s;
}