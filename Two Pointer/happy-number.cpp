#include<iostream>
using namespace std;
// 快乐数：将一个数各个位上的数字平方和相加得到新数,如果重复操作能得到1，则该数是快乐数
//快慢指针法：注意到1不管多少次操作都不会变，因此我们让快慢指针不断移动直到相遇，判断相遇点是不是1即可
int sum(int n) //求新数
{
    int sum = 0;
    while (n > 0)
    {
        int x = n % 10;
        sum += x * x;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) 
{
    int slow = n, fast = n; //快指针一次变两个新数,慢指针一次变一个新数
    do
    {
        slow = sum(slow);
        fast = sum(fast);
        fast = sum(fast);
    } while (slow != fast); //相遇时循环结束
    return slow == 1; //判断此时是不是1
}