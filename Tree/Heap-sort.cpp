#include <iostream>
#include <vector>
using namespace std;
// 堆排序
//对一个非叶节点进行调整  index是第一个非叶节点
void BuildHeap(vector<int> &arr, int len, int index)
{
    int left = index * 2 + 1;  //index的左子节点//
    int right = index * 2 + 2; //index的右子节点//
    int maxindex = index;
    //比较index的左右子节点值与index节点值的大小,从而确定是否要进行调整//
    if (left < len && arr[left] > arr[maxindex]) //注意不是index，因为递归后处理的是maxindex的值//
        maxindex = left;                         //要调整左子节点//
    if (right < len && arr[right] > arr[maxindex])
        maxindex = right; //要调整右子节点//
    /*
        下面对要调整的节点进行交换
        为了方便理解，把平衡二叉树比喻成一个单位，一层层的节点就是一层层领导，
        本来应该是最高层领导能力最强，但是现在发现很多领导没有下属能力强，那么
        就要将领导的位置跟下属的位置互换(即将index节点与比它值大的子节点交换),
        但是交换后发现原来的领导还没有他下属的下属能力大(即与index节点交换的子节点的子节点依然比index节点的值大)，
        所以继续把这个能力不足的领导和他下属的下属进行交换(即递归部分)，直到
        所有人的能力都与他们的位置相匹配，此时第一个节点调整完毕
    */
    if (maxindex != index) //递归地向下构建
    {
        swap(arr[maxindex], arr[index]);
        BuildHeap(arr, len, maxindex);
    }
}

void HeapSort(vector<int> &arr, int len)
{
    //构建最大堆(对所有非叶节点都要进行调整)
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        BuildHeap(arr, len, i);
    }

    /*
        下面是堆排序的主体部分：把最大堆顶端根节点(值最大的)与底端最小值的节点交换
        然后最大值就来到了末尾，之后把剩下的无序序列调整成最大堆，重复上面的操作，
        直到所有节点的值按顺序排列，那么排序结束！
    */
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        BuildHeap(arr, i, 0); //这里只要调整根节点即可,因为其他部分已经调整好
    }
}
int main()
{
    vector<int> arr = {9, 7, 10, 12, 5, 4, 2, 1, 15, 14, 3, 7, 8, 6, 11, 13};
    HeapSort(arr, arr.size());
    for(auto i:arr)
        cout << i << " ";
    cout << endl;
    return 0;
}