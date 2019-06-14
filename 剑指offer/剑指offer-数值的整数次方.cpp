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
 
