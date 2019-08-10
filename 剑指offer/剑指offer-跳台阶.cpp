/*
Create By @herongwei 2019/08/10
【题目描述】
一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
【思路】
*/
class Solution {
public:
    int jumpFloor(int number) {
    if (number <= 2)
        return number;
    int f2 = 1, f1 = 2;
    int ret = 1;
    for (int i = 2; i < number; ++i) {
        ret = f2 + f1;
        f2 = f1;
        f1 = ret;
    }
    return ret;
    }
};
