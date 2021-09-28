#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 使用低位基数排序对单词按照字典序排序。
// n个单词，每个单词三个字母（只包含小写字母）
vector<vector<string>> radixSort(vector<string> &bucket,int n)
{
    vector<vector<string>> res(26); //26个桶对应26个字母，每个桶最多有n个单词
    vector<int> nums(26,0); //记录每个桶中元素的个数
    for (int i = 0; i < n; i++)     //第一次分配，遍历原来的数组，按照个位分入对应的桶
    {
        res[bucket[i][2] - 'a'].push_back(bucket[i]);
        nums[bucket[i][2] - 'a']++; //桶元素个数修改
    }
    for (int i = 0; i < 26; i++) //第二次分配,遍历所有桶，从桶底不断取出单词，按照十位分配放入对应桶
    {
        if (res[i].empty())
            continue;
        int s = nums[i]; //每个桶的大小
        for (int j = 0; j < s; j++)
        {
            string front = res[i][0];             //桶底单词
            res[i].erase(res[i].begin());         //删除桶底单词
            res[front[1] - 'a'].push_back(front); //按照十位分配
            nums[i]--;                     //更新元素个数
            nums[front[1] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) //第二次分配,遍历所有桶，从桶底不断取出单词，按照百位分配放入对应桶
    {
        if (res[i].empty())
            continue;
        int s = nums[i];
        for (int j = 0; j < s; j++)
        {
            string front = res[i][0];
            res[i].erase(res[i].begin());
            res[front[0] - 'a'].push_back(front);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> bucket(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        bucket[i] = x;
    }
    vector<vector<string>> res(26);
    res = radixSort(bucket,n);
    for (int i = 0; i < 26; i++)
    {
        int s = res[i].size();
        for (int j = 0; j < s; j++)
        {
            if (!res[i][j].empty())    //注意有的地方是空的
                cout << res[i][j] << " ";
        }
    }
    return 0;
}