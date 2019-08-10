/*
Create By @herongwei 2019/08/10
【题目描述】
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
【思路】
要覆盖 2*n 的大矩形，可以先覆盖 2*1 的矩形，再覆盖 2*(n-1) 的矩形；或者先覆盖 2*2 的矩形，再覆盖 2*(n-2) 的矩形。
而覆盖 2*(n-1) 和 2*(n-2) 的矩形可以看成子问题。该问题的递推公式就是斐波那契数列
*/
class Solution {
public:
    int rectCover(int number) {
    if (number <= 2) return number;
    int f1 = 1, f2 = 2;
    int fn = 0;
    for (int i = 3; i <= number; ++i) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
    }
};
