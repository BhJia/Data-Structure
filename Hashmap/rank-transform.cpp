#include<bits/stdc++.h>
using namespace std;
vector<int> arrayRankTransform(vector<int> &arr)
{
    set<int> s(arr.begin(), arr.end());
    for (auto &i : arr)
        i = distance(s.begin(), s.find(i)) + 1;
    return arr;
}