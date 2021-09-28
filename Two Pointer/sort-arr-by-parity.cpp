#include <bits/stdc++.h>
using namespace std;
// 按奇偶性排序数组：输入数组，将奇数放在偶数后面
// 与反转元音字母一样的双指针法左右指针分别向中间移动，左边移动到奇数，右边移动到偶数的时候交换，继续上述操作直到左右指针相遇
vector<int> sortArrayByParity(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        while (l < r && nums[l] % 2 == 0)
            l++;
        while (l < r && nums[r] % 2 != 0)
            r--;
        if (l < r)
            swap(nums[l], nums[r]);
    }
    return nums;
}
