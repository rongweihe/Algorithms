/*
Author: github.com/rongweihe
Date  : 2019-04-13
题目  : 手写 Power 函数
input : 25.5 5
output: 10782039.093750
两个细节:【1】判断base是否等于0？负数？【2】用位运算替代乘除法及求余运算
*/
#include <bits/stdc++.h>
using namespace std;
const double eps = 0.0000001;
bool g_InvalidInput = false;//判断输入是否合法
bool equal(double num1, double num2)
{
    if( (num1 - num2 > -eps) && (num1 - num2 < eps) )
        return true;
    else
        return false;
}
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double ret = PowerWithUnsignedExponent(base, exponent >> 1);
    ret*=ret;
    if(exponent & 0x1 == 1)
        ret*=base;
    return ret;
}
double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if( equal(base,0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int) (exponent);
    if(exponent <0)
        absExponent = (unsigned int) (-exponent);
    double ret = PowerWithUnsignedExponent(base,absExponent);
    if(exponent <0)
        ret = 1.0/ret;
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    double ret = Power(25.5,5);
    printf("%f\n",ret);//10782039.093750
    return 0;
}
 

//另外的版本

/*
Create By @herongwei 2019/08/10
【题目描述】
给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent。求 base 的 exponent 次方。
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
    double Power(double base, int exp)
    {
        if (equal(base,0))
        {
            if (exp > 0)
                return 0;
            else if (exp == 0)
                return 0;
            else
            {
                bool g_InvalidInput = true;
                throw invalid_argument("Invalid input!");
            }
        }
        else
        {
            if (exp > 0)
                return power(base, exp);
            else if (exp == 0)
                return 1;
            else
                return 1 / power(base, -exp);
        }
    }
public:
    bool equal(double e1,double e2)
    {
        if(e1-e2>-eps && e1-e2<eps)
        {
            return true;
        }
        return false;
    }
    double power(double base, int exp)
    {
        if (exp == 1)
            return base;
        //指数是偶数
        if ((exp & 1) == 0)
        {
            int tmp = power(base, exp >> 1);
            return tmp * tmp;
        }
        else
        {
        //指数是奇数
            int tmp = power(base, (exp - 1) >> 1);
            return tmp * tmp * base;
        }
    }
private:
    bool g_InvalidInput = false;
    const double eps = 1e-8;
};


