#include<bits/stdc++.h>
using namespace std;

// 递归版
int binarySearch( int array[], int low, int high, int key)
{
    if(low>high)
        return -1;
    int mid = (low + high) / 2;
    if (array[mid] == key)
        return mid;
    else if (array[mid] < key)
        return binarySearch(array, mid + 1, high, key);
    else
        return binarySearch(array, mid - 1, low, key);
}

// 非递归双指针版
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else if (nums[mid] < target)
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n,k;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }
    cin >> k;
    cout << binarySearch(array, 0, n-1, k)<<endl;
    return 0;
}