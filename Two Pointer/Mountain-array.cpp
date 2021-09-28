#include<bits/stdc++.h>
using namespace std;
// 山脉数组：给定一个数组，判断是否满足先增后减,且增减性只变一次
// 双指针,左右同时向中间移动,看能否相遇
bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;
    int l = 0, r = arr.size() - 1;
    while (l < r && arr[l] < arr[l + 1]) //注意这里l<r是前提，所以必须先进性判断
        l++;
    while (l < r && arr[r] < arr[r - 1])
        r--;
    return l == r && l != 0 && r != arr.size() - 1;
}

// 求山脉数组山峰索引
int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0, r = arr.size() - 1;
    while (l < r && arr[l] < arr[l + 1]) 
        l++;
    while (l < r && arr[r] < arr[r - 1])
        r--;
    return l;
}

// distance直接求最大值下标
int peakIndexInMountainArray(vector<int> &arr)
{
    return distance(arr.begin(), max_element(arr.begin(), arr.end()));
}