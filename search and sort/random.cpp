#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

vector<int> generator(int N,int s,int t, string T)
{
    srand(time(0));
    vector<int> res;
    for(int i = 0; i < N; i++)
        res.push_back(rand() % (t - s + 1) + s);
    if(T=="increase")
        sort(res.begin(),res.end());
    else if(T=="decrease")
        sort(res.begin(),res.end(),greater<int>());
    return res;
}

void Merge(vector<int> &arr, int low, int mid, int high)
{
    //两个待合并有序数组:(low,mid),(mid+1,high)
    int i = low, j = mid + 1, k = 0;
    int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
    while (i <= mid && j <= high)
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= mid) //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++];
    while (j <= high) //同上
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++) //将排好序的存回arr中low到high这区间
        arr[i] = temp[k];
    delete[] temp; //释放内存，由于指向的是数组，必须用delete []
}

void MergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (high + low) / 2;
    MergeSort(arr, low, mid); //将数组分割分别排序,然后再合并
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

void InsertSort(vector<int> &a, int n)
{
    for (int j = 1; j < n; j++) //从第二个数开始
    {
        int key = a[j];    //记录待插入排序的数
        int i = j - 1;     //从待排序数位置向前查找
        while (a[i] > key) //如果当前数比待排序数大,就将当前数右移,直到找到第一个比待排序数小的数
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key; //把待排序数插入到该数后面
    }
}

int main()
{
    vector<int> res = generator(pow(10,5), 0, pow(10,7), "");
    vector<int> temp = res;
    double start, end, diff=0;
    for (int i = 0; i < 1; i++)
    {
        start = clock();
        res = temp;
        bubbleSort(res,res.size());
        end = clock();
        diff += (end - start) / CLOCKS_PER_SEC;
    }
    cout << diff;
    return 0;
}