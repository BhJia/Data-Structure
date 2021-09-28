#include<bits/stdc++.h>
using namespace std;
// 复写0：给定数组，遇到0，在后面添一个0，并把数组所有元素右移，但保持数组长度不变
// 思路：遇到0 insert 0,先不管长度，最后再用resize函数重新调整数组长度
void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 0)
            arr.insert(arr.begin() + (i++), 0);
    arr.resize(n);
}