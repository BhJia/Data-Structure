#include<bits/stdc++.h>
using namespace std;
// 统计最大组的数目：给定一个整数n,将1到n按照数位和分组，相同数位和放在一组，求相同数位和最多的组的个数
// c++哈希表统计相同数位和出现次数，按照出现次数降序
int digitsum(int n)
{
    int sum = 0;
    if (n < 10)
        return n;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int countLargestGroup(int n)
{
    map<int, int> m;
    vector<int> temp;
    for (int i = 1; i <= n; i++)
        m[digitsum(i)]++;
    for (auto p : m)
        temp.push_back(p.second);
    sort(temp.begin(), temp.end(), [&](int &a, int &b) { return a > b; });
    int maxnum = temp[0], res = 0;
    for (auto i : temp)
        if (i == maxnum)
            res++;
    return res;
}