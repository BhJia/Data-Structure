#include<bits/stdc++.h>
using namespace std;
// 给定数组代表卡牌点数,每次只能从头尾取一张牌,求取K次卡牌点数之和最大值
// 分析：逆向思维,正面想很难做,反过来考虑,只要求拿完牌剩下的点数最小值，而剩下牌必然连续，因此想到滑动窗口
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int windowsSize = n - k;  //滑动窗口长度
    int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowsSize, 0); //构建和的滑动窗口
    int minSum = sum; 
    for (int i = windowsSize; i < n; i++)
    {
        sum += cardPoints[i] - cardPoints[i - windowsSize]; //移动滑动窗口
        minSum = min(minSum, sum);    //跟新最小值
    }
    return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
}