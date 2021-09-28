#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//Tuple 元组问题

// 回旋镖的数量:给定一个点集，一个回旋镖是指一个有序点组(i,j,k),其中i,j和i,k之间的距离相等
// 思路很巧妙：本来是要三重遍历对每个点查找两组距离相等的点组;
// 现在我们只要对每个点，用哈希表存储改点与其它点相同距离的个数,任意一个相同距离个数为n，则回旋镖有C(n,2)个
int numberOfBoomerangs(vector<vector<int>> &points)
{
    int res = 0;
    for (auto i : points) //遍历每个点
    {
        map<int, int> dis;    //建立该点距离到个数的临时哈希表
        for (auto j : points) //再次遍历,更新表中距离的次数
            dis[pow(j[0] - i[0], 2) + pow(j[1] - i[1], 2)]++;
        for (auto p : dis)   //遍历哈希表,更新答案
            res += p.second * (p.second - 1);
    }
    return res;
}

// 同积元问题：给定一个数组,找到四个不同整数a,b,c,d,使得a*b=c*d，求这样的四元元组个数
// 方法：将四元转化为两个两元组,则题目转化为：给定一个数组，求两个同积两元组
//与上一题的方法类似：双重遍历用哈希表记录所有二元组乘积次数
//n个同积二元组任取两个组成同积二元组对可以组成C(n,2)个,而一个二元组对换位可以产生8个同积四元组
int tupleSameProduct(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            m[nums[i] * nums[j]]++;
        }
    }
    for (auto p : m)
        sum += p.second * (p.second - 1) * 4;
    return sum;
}