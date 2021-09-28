#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
/* STL语法补充：
1、map中的元素类型是对组pair,map的遍历可以迭代器也可以for循环，for(auto x:map) 
  但是注意：迭代器是指针，要用m->first/second;而循环只需要m.first/m.second即可
2、可以通过拷贝构造直接将map中的所有对组元素放入vector容器，即vec(map.begin(),map.end());
3、string可以拷贝构造但不能只有一个表示大小的数字*/

// 本题：重构字符串:重新排列字符串使其没有两个相邻的相同元素
// 思路：贪心思想：先把出现频率最高的字符间隔排列，然后把频率第二高的字符插空看是否能插满
// 方法：哈希表+数组：先用哈希表统计字符频率，然后把字符及其频率按照频率降序放到数组中，最后插空
string reorganizeString(string S)
{
    map<char, int> m; 
    int maxFreq = 0;
    for (auto x : S) //遍历字符串，用哈希表存放字符+频率
    {
        m[x]++;
        maxFreq = max(maxFreq, m[x]); //顺便求出最大频率的字符
    }
    if (maxFreq * 2 - 1 > S.size()) //如果去掉频率最高的字符剩下的字符不能插满空，则说明无法满足条件，返回空串
        return "";
    vector<pair<char, int>> times(m.begin(), m.end()); //把哈希表里所有字符和频率的对组放入数组并按照频率降序
    sort(times.begin(), times.end(), [&](pair<char, int> &a, pair<char, int> &b) { return a.second > b.second; });
    string res(S); //重构后的字符串
    int index = 0; //先把频率最高的字符放在偶数位，在奇数位插空
    for (auto x : times)
    {
        while (x.second--)
        {
            res[index] = x.first;
            index += 2; 
            if (index >= S.size())  //如果奇数位插满了就在奇数位放字母，偶数位插空
                index = 1;
        }
    }
    return res;
}