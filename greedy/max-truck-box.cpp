#include<bits/stdc++.h>
using namespace std;
// 卡车上的最大单元：给定一系列盒子，盒子两个参数分别是个数和容量，给定卡车可以放下的最大盒子个数，返回卡车装下盒子的最大总容量
// 贪心：自定义排序后取容量大的
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    int sum = 0;
    sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    });
    for (auto i : boxTypes)
    {
        int num = min(truckSize, i[0]); //比较当前盒子个数与剩余的卡车盒子个数
        sum += num * i[1];
        truckSize -= num;  //更新剩余的卡车盒子个数
        if (truckSize == 0) //如果卡车装满了就不继续下去
            break;
    }
    return sum;
}