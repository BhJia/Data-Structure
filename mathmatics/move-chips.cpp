#include<bits/stdc++.h>
using namespace std;
// 移动筹码：给定一个数组，nums[i]=2代表2的位置有一个筹码，现在要把所有筹码移动到一个位置,移动两步不需要代价，移动一步需要代价1，求
// 最小代价。可以把所有“奇数位置”筹码移动到一个点A（奇数位置），且不必花费任何代价；
// 同理，所有“偶数位置”的筹码移动到点B（偶数位置）也不需要任何代价。
// 最终就是看A,B两点谁的筹码数多，把少的筹码移动到多的筹码的位置，每一个筹码的代价都是1。
int minCostToMoveChips(vector<int> &position)
{
    int odd = 0, even = 0;
    for (auto i : position)
        i % 2 ? odd++ : even++;
    return min(odd, even);
}