#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//本题是一道很好的题目！！
/* 先补充STL语法知识：
1、reverse(a,b)反转的是从a迭代器指向的元素到b指向元素的前一个元素而非该元素
2、a.end()指向的是数组的最后一个元素再后面一个
3、distance函数：distance(a,b)返回a,b迭代器之间的距离(对应下标之差)
4、auto关键字可以表示迭代器类型
5、max_element(a,b),min_element(a,b)返回a迭代器到b迭代器之间序列的最大最小值 */

/* 
    再看本题：煎饼排序：
    1、选择整数k(1<=k<=arr.size()),反转子数组arr[0,1,2……,k-1];
    2、重复1的操作直到数组有序
    3、记录每次操作的k值

    思路：
    1、每次遍历找到最大元素,反转开头到最大元素的数组，这样最大元素就到了第一个,再整个反转，最大元素就到了末尾。
    2、再对开头到最大元素前的子数组进行1的操作，这样第二大的元素就到了末尾；
    3、不断操作直到数组有序
 */
vector<int> pancakeSort(vector<int> &arr)
{
    vector<int> res;   //记录每次反转下标k的数组
    int k = 0, d = 0;  //k是操作次数
    while (k < arr.size())
    {
        auto x = max_element(arr.begin(), arr.end() - k); //找到本次操作数组的最大元素
        if (x == arr.end() - (k + 1)) //如果该元素已经在本次操作数组的末尾,那就不需要反转
        {
            k++;
            continue;
        }
        d = distance(arr.begin(), x) + 1; //求出本次反转坐标(注意+1)
        if (d > 1)     //如果d=1说明这个最大元素在开头,那直接反转本次操作的整个数组
        {
            res.push_back(d);
            reverse(arr.begin(), x + 1);
        }
        reverse(arr.begin(), arr.end() - k);  //反转本次操作的整个子数组,让最大元素到子数组末尾
        res.push_back(arr.size() - k); //记录反转下标
        k++;
    }
    return res;
}