/*
*计算定积分
*(878^(1/2)*int(r*(r^2/((1072982611221*r^2)/1125899906842624 + 3600000000) + 1)^(1/2), r, 0, 15000)^(1/2))/439
*分别用梯形法和牛顿—柯特斯（Newton-Cotes）求积公式对比
*Create By@herongwei 2019/08/19
*/

#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
typedef long long LL;


class getDefiniteIntegral
{
public:
    double getFun(double r)
    {
        long  double x1 = 1072982611221*1.0;
        long  double x2 = 1125899906842624*1.0;
        long  double x3 = 3600000000*1.0;
        double y = 1.0*r*r/(((1.0*x1*r*r)/x2 + x3)) + 1.0;
        return  1.0*r*sqrt(y);
    }
    double Sinx(double x)
    {
        return sin(x);
    }
//梯形法
//函数功能：计算函数在[a,b]的定积分
//参数1：函数指针；参数2：积分上限；参数3：积分下限；参数4：步长(默认0.01)
    double funTrapezoid(double a, double b, double step)
    {
        double w; //每个小矩形的面积
        double k=(b-a)/step;//k就是每个矩形的底
        double s=0.0;
        for(double i=1; i<=step; ++i)
        {
            //w = getSinx(a+(i-1)*k)*k; //sinx从0到1的定积分约等于 0.46
            w=getFun(a+(i-1)*k)*k;
            s = s + w;
        }
        return s;
    }
    double newtonCotes(double a,double b)
    {
        double c1,c2,c3;
        c1=(a+b)/2.0;
        c2=(a+c1)/2.0;
        c3=(c1+b)/2.0;
        return 1.0*(b-a)/90*(7*getFun(a)+32*getFun(c2)+12*getFun(c1)+32*getFun(c3)+7*getFun(b));
    }
    //用梯形法计算
    double getRet(double a,double b,double step)
    {
        double tmp = funTrapezoid(a,b,step);
        tmp=(1.0)*sqrt(tmp*1.0);
        tmp*=(1.0)*sqrt(878*1.0);
        tmp/=(1.0)*439;
        return tmp;
    }
    //用牛顿—柯特斯（Newton-Cotes）求积公式
    double getNewtonCotes(double a,double b)
    {
        double tmp = newtonCotes(a,b);
        tmp=(1.0)*sqrt(tmp*1.0);
        tmp*=(1.0)*sqrt(878*1.0);
        tmp/=(1.0)*439;
        return tmp;
    }
};
int main()
{
    double ret1 =0;
    double ret2 =0;
    getDefiniteIntegral g;
    ret1 = g.getRet(0,150000,150000000);//参数：上限，下限，步长
    ret2 = g.getNewtonCotes(0,150000);
    printf("%.10f\n",ret1);//传统 梯形法 计算
    printf("%.10f\n",ret2);//牛顿—柯特斯公式
    return 0;
}
