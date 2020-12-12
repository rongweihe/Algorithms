/*
Create By @herongwei 2019/08/10
【题目描述】
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
【思路】
该位运算去除 n 的位级表示中最低的那一位。

n       : 10110100
n-1     : 10110011
n&(n-1) : 10110000
时间复杂度：O(M)，其中 M 表示 1 的个数。
*/

class Solution
{
public:
    int NumberOf1(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
};
