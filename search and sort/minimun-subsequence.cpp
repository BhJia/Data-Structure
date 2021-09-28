#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;
//STL语法补充：accumulate(a,b,x)返回从迭代器a到b，以x为初始值的和(注意：要加入numeric头文件)
//最小子序列:在一个数组中抽取一些数构成子序列,使这些数的和大于剩下数的和，求长度最小的子序列
//思路：贪心思想：要想长度小且和大,就要取数值大的元素
//方法：求和后降序排序,从最大的数开始取直到和超过剩下的
vector<int> minSubsequence(vector<int> &nums)
{
    vector<int> res;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int sum1 = 0;
    sort(nums.begin(), nums.end(), [&](int &a, int &b) { return a > b; });
    for (int x : nums)
    {
        res.push_back(x);
        sum1 += x;
        sum -= x;
        if (sum1 > sum)
            break;
    }
    return res;
}