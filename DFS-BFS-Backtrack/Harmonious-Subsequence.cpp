#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> res;
void backtrack(vector<int> &nums, vector<int> &path, int start)
{
    if (*max_element(path.begin(), path.end()) == *min_element(path.begin(), path.end()) + 1)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < nums.size(); i++) //状态变量为sum和start
    {
        path.push_back(nums[i]);
        backtrack(nums, path, i + 1);
        path.pop_back();
    }
}
int findLHS(vector<int> &nums)
{
    vector<int> path;
    backtrack(nums, path, 0);
    sort(res.begin(), res.end(), [&](vector<int> &a, vector<int> &b) {
        return a.size() > b.size();
    });
    return res[0].size();
}


void inputArr(vector<int> &arr)
{
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
        if (cin.get() == '\n')
            break;
    }
}

int main()
{
    vector<int> nums;
    inputArr(nums);
    cout << findLHS(nums);
    return 0;
}