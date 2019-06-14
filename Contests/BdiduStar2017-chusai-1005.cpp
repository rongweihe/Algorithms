/* ***********************************************
Author        :herongwei
Created Time  :08-12 2017 22:31:17 PM CST
File Name     :hdu-6112.cpp

 今夕何夕

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 1063    Accepted Submission(s): 368


Problem Description
今天是2017年8月6日，农历闰六月十五。

小度独自凭栏，望着一轮圆月，发出了“今夕何夕，见此良人”的寂寞感慨。

为了排遣郁结，它决定思考一个数学问题：接下来最近的哪一年里的同一个日子，和今天的星期数一样？比如今天是8月6日，星期日。下一个也是星期日的8月6日发生在2023年。

小贴士：在公历中，能被4整除但不能被100整除，或能被400整除的年份即为闰年。
 

Input
第一行为T，表示输入数据组数。

每组数据包含一个日期，格式为YYYY-MM-DD。

1 ≤ T ≤ 10000

YYYY ≥ 2017

日期一定是个合法的日期

 

Output
对每组数据输出答案年份，题目保证答案不会超过四位数。
 

Sample Input
3
2017-08-06
2017-08-07
2018-01-01
 

Sample Output
2023
2023
2024
 

Source
2017"百度之星"程序设计大赛 - 初赛（A）

[solution]
基姆拉尔森公式的应用，注意一下2月29号的情况

************************************************ */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <numeric>
#include <limits>

using namespace std;
typedef long long LL;
const int maxn  = 1e5+2333;
const int MOD   = 1e9+7;
const LL inf   = 0x3f3f3f3f;
const double eps= 1e-8;
const double pi = acos(-1.0);
int n,m,t,tot,cnt,ans,ret,tmp;
inline int read()
{
    int  c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar(); }
    while(ch>='0'&&ch<='9'){c=c*10+ch-'0';ch=getchar();}
    return c*f;
}

bool is_run(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)  return true;
    else  return false;
}
int calc_week(int y, int m, int d)
{
    int w;
    if(m==1||m==2)
    {
        m+=12;
        y-=1;
    }
    w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
    return w;
}
int main()
{
    t=read();
    while(t--)
    {
        int y, m, d;
        scanf("%d-%d-%d", &y, &m, &d);
        int p = calc_week(y, m, d);
        bool f=false;
        if(m==2&&d==29&&is_run(y)) f=true;
        for(int y1 = y+1; ; y1++)
        {
            if(f)
            {
                if(calc_week(y1, m, d) == p&&is_run(y1))
                {
                    printf("%d\n", y1);
                    break;
                }
            }
            else
            {
                if(calc_week(y1, m, d) == p)
                {
                    printf("%d\n", y1);
                    break;
                }
            }
        }
    }
    return 0;
}


