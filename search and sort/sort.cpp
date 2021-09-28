#include <bits/stdc++.h>
using namespace std;
// 插入排序
void InsertSort(int a[], int n)
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

// 冒泡排序:每次排序确定当前最大值放在当前排序序列末尾
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void Merge(int arr[], int low, int mid, int high)
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

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (high - low) / 2;
    MergeSort(arr, low, mid);  //将数组分割分别排序,然后再合并
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

// 在待排线性表中取一个元素pivot作为枢轴值，通过一趟排序将待排线性表划分为独立的两部分，
// 第一部分的所有元素小于pivot，第二部分的所有元素大于等于pivot，pivot位于其最终位置。递归对两个子表做快速排序。
// int partition(vector<int> &a, int low, int high)
// {
//     // 枢轴值（线性表第一个元素作为枢轴值）
//     int key = a[low];
//     while (low < high)
//     {
//         // 从右侧找小于pivot的值，替换low位置的元素
//         while (low < high && a[high] >= key)
//             --high;
//         a[low] = a[high];

//         // 从左侧找大于pivot的值，替换high位置的元素
//         while (low < high && a[low] <= key)
//             ++low;
//         a[high] = a[low];
//     }
//     a[low] = key;
//     return low; // 返回一趟排序后确定的元素位置
// }

int partition(vector<int> &a, int low, int high)
{
    // 枢轴值（线性表第一个元素作为枢轴值）
    int key = a[low];
    while (low < high)
    {
        // 从右侧找小于pivot的值，与之交换
        while (low < high && a[high] >= key)
            --high;
        swap(a[low], a[high]);

        // 从左侧找大于pivot的值，与之交换
        while (low < high && a[low] <= key)
            ++low;
        swap(a[low], a[high]);
    }
    return low; // 返回一趟排序后确定的元素位置
}

//快速排序的递归形式
void QuickSort(vector<int> &a, int low, int high)
{
    if (low < high) // 递归出口
    {
        int loc = partition(a, low, high); //一趟排序结果的调用
        QuickSort(a, low, loc - 1);
        QuickSort(a, loc + 1, high);
    }
}

// LSD:低位基数排序
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0]; 
    for (int i = 1; i < n; ++i) //求最大数
        if (maxData < data[i])
            maxData = data[i];
    int d = 0;
    while(maxData)
    {
        d++;
        maxData /= 10;
    }
    return d;
}

void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n); //所有数的最大位数
    int *tmp = new int[n]; //这里只需要一个一维数组,相当于把所有不同的桶展开放到一起
    int *count = new int[10]; //计数器：记录每个桶在tmp数组中对应的位置索引(第i个桶位置：count[i-1]到count[i]-1)
    int i, j, k;
    int radix = 1; //每次排序完成都*10,这样下次就是求更高位的数
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)  //每次分配前清空计数器
            count[j] = 0; 
        for (j = 0; j < n; j++)  //统计每个桶中的记录数
        {
            k = (data[j] / radix) % 10; //当前数位的数
            count[k]++;
        }
        for (j = 1; j < 10; j++)   //记录每个桶在tmp中对应的位置索引
            count[j] = count[j - 1] + count[j]; 
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中(从后往前放)
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;  //把该桶右边界索引前移
        } 
        for (j = 0; j < n; j++)  //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
}