#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    /* 本题是一道好题
    下一个更大元素：两个没有重复元素的数组nums1和nums2其中nums1 是 nums2 的子集。
    找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
    nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
    如果不存在，对应位置输出 -1 。

    解法：单调栈+哈希表
    类似于每日温度,在nums2中用单调递减栈求出每个元素下一个更大元素，然后用哈希表形成对应
    再在nums1中遍历查找
    */

    unordered_map<int, int> m;
    stack<int> s;
    vector<int> res(nums1.size(), -1);
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!s.empty() && nums2[i] > nums2[s.top()])
        {
            m[nums2[s.top()]] = nums2[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (m.count(nums1[i]))
        {
            res[i] = m[nums1[i]];
        }
    }
    return res;
}

// 循环数组每个元素的下一个最大元素：把循环数组前n-1个元素复制到数组末尾，这样就变成了普通数组
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (!s.empty() && nums[i % n] > nums[s.top()])
        {
            res[s.top()] = nums[i % n];
            s.pop();
        }
        s.push(i % n);
    }
    return res;
}

// 商品折扣后的最终价格
vector<int> finalPrices(vector<int> &prices)
{
    if (prices.empty())
        return {};
    int n = prices.size();
    vector<int> res(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && prices[i] <= prices[s.top()])
        {
            res[s.top()] = prices[s.top()] - prices[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        res[s.top()] = prices[s.top()];
        s.pop();
    }
    return res;
}

void inputArr(vector<int> &arr)
{
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
    }
}

void Print1(vector<int> &arr)
{
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " " << endl;
    }
}

int main()
{
    vector<int> nums1, nums2,res;
    inputArr(nums1);
    inputArr(nums2);
    res = nextGreaterElement(nums1, nums2);
    Print1(res);
    return 0;
}