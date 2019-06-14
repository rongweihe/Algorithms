/*
hdu-2092 Problem Description
有二个整数，它们加起来等于某个整数，乘起来又等于另一个整数，它们到底是真还是假，也就是这种整数到底存不存在，实在有点吃不准，你能快速回答吗？看来只能通过编程。
例如：
x + y = 9，x * y = 15 ? 找不到这样的整数x和y
1+4=5，1*4=4，所以，加起来等于5，乘起来等于4的二个整数为1和4
7+(-8)=-1，7*（-8）=-56，所以，加起来等于-1，乘起来等于-56的二个整数为7和-8


Input
输入数据为成对出现的整数n，m（-10000<n,m<10000），它们分别表示整数的和与积，如果两者都为0，则输入结束。


Output
只需要对于每个n和m，输出“Yes”或者“No”，明确有还是没有这种整数就行了。


Sample Input
9 15
5 4
1 -56
0 0


Sample Output
No
Yes
Yes


Author
qianneng
*/

/* ***********************************************
Author        :herongwei
Created Time  :Fri 14 Jul 2017 16:00:23 AM CST
File Name     :hdu-2092.cpp
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

using namespace std;
typedef long long LL;
const int maxn  = 2333;
const int MOD   = 1e9+7;
const int inf   = 0x3f3f3f3f;
const double eps= 1e-8;
const double pi = acos(-1.0);
int n,m,t,dis[maxn],g[233][233];
bool vis[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        double x1,x2;
        if(n*n-4*m>=0)
        {
            x1=(n+sqrt(n*n-4*m))/2;
            x2=(n-sqrt(n*n-4*m))/2;
            if( fabs(x1-(int)x1)<eps || fabs(x2-(int)x2)<eps) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
    return 0;
}

