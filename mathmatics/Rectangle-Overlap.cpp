#include<bits/stdc++.h>
using namespace std;
// 矩形重叠：给定两个平行坐标轴的矩形的左下角和右上角坐标，判断它们是否有重叠
// 思路：1、首先判断两个点能否构成矩形  2、如果能构成矩形，矩形投影到x,y轴上是一条线，那么只要x轴上投影的两条线不重叠
// y轴上投影的两条线不重叠即可
bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    if (rec1[2] == rec1[0] || rec1[1] == rec1[3] || rec2[2] == rec2[0] || rec2[1] == rec2[3])
        return false;
    return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
}