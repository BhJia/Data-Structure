#include<bits/stdc++.h>
using namespace std;
// 卡牌分组：把所有卡牌分成若干个组，每个组卡牌数大于等于2且点数相同,判断是否可以分成这样的组
// 思路：每种卡牌出现次数的最大公约数就是每组的最大卡牌数，所以只要判断最大公约数是否大于1即可
// 补充知识：gcd(x,y)求x,y的最大公约数
bool hasGroupsSizeX(vector<int> &deck)
{
    int temp = INT_MAX;
    map<int, int> m;
    vector<int> res;
    if (deck.size() == 1)
        return false;
    for (auto i : deck)
        m[i]++;
    for (auto p : m)
        res.push_back(p.second);
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] == 1)
            return false;
        temp = min(gcd(res[i], res[i - 1]), temp);
    }
    return temp >= 2;
}