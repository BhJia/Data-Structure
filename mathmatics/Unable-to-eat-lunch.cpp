#include<bits/stdc++.h>
using namespace std;
// 无法吃午餐学生数量：有两种三明治，分别用0/1表示，每个学生喜欢吃其中一种。给定两个数组，最前面的学生如果喜欢吃最前面的三明治
// 就拿走三明治离开，否则移动到队尾，直到没有人拿到喜欢的三明治，返回剩下的学生人数
// 思路：比较巧妙：因为三明治个数和学生个数相等，所以用cnt数组记录两种三明治剩下的个数，遍历学生拿喜欢的，剩下的三明治个数就是
// 没吃到三明治的学生个数
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    vector<int> cnt(2, 0);
    for (auto i : students)
        cnt[i]++;
    for (auto i : sandwiches)
    {
        if (cnt[i])
            cnt[i]--;
        else
            break;
    }
    return cnt[0] + cnt[1];
}