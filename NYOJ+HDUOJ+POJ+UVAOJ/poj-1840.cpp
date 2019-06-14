/*
poj-1840  Eqs 
Consider equations having the following form: 
a1x1 3+ a2x2 3+ a3x3 3+ a4x4 3+ a5x5 3=0 
The coefficients are given integers from the interval [-50,50]. 
It is consider a solution a system (x1, x2, x3, x4, x5) that verifies the equation, xi∈[-50,50], xi != 0, any i∈{1,2,3,4,5}. 

Determine how many solutions satisfy the given equation. 
Input
The only line of input contains the 5 coefficients a1, a2, a3, a4, a5, separated by blanks.
Output
The output will contain on the first line the number of the solutions for the given equation.
Sample Input
37 29 41 43 47
Sample Output
654
*/

/*
 给你一个五元三次方程，给出五个未知数的系数，每个系数和未知数的范围均属于【-50,50】求满足等式结果为0的情况下五个未知数的个数的总数。
【思路】
直观的思路：暴力枚举，复杂度：O(n^5)
题目Time Limit=5000ms，1ms大约可以执行1000条语句，那么5000ms最多执行500W次
每个变量都有100种可能值，那么暴力枚举，5层循环，就是要执行100^5=100E次，然后果断等着TLE吧。。。。
 一般这种数学题，应该还要想到变形吧～～
 然后试试，对方程做一个变形：
-(a1*x1^3+a2*x2^3)=a3*x3^3+a4*x4^3+a5*x5^3;
 即先枚举x1和x2的组合，把所有出现过的 左值 记录打表，然后再枚举x3 x4 x5的组合得到的 右值，如果某个右值等于已经出现的左值，那么我们就得到了一个解
 时间复杂度从 O(n^5)降低到 O(n^2+n^3)，大约执行100W次。用到hash

*/
/* ***********************************************
Author        :herongwei
Created Time  :2017年07月02日 星期日 20时49分58秒
File Name     :poj1840.cpp
Consider equations having the following form:
a1x1 3+ a2x2 3+ a3x3 3+ a4x4 3+ a5x5 3=0
The coefficients are given integers from the interval [-50,50].
It is consider a solution a system (x1, x2, x3, x4, x5) that verifies the equation, xi∈[-50,50], xi != 0, any i∈{1,2,3,4,5}.
Determine how many solutions satisfy the given equation.
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
const int maxn  = 12500000+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);
int a1,a2,a3,a4,a5;
short hashh[2*maxn+1],l=-50,r=50;
int tmp,ans;
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5))
    {
        memset(hashh,0,sizeof(hashh));
        for(int x1=l; x1<=r; ++x1 ){if(!x1)continue;
            for(int x2=l; x2<=r; ++x2 ){if(!x2)continue;
                tmp=maxn-(a1*x1*x1*x1+a2*x2*x2*x2);//避免出现负数
                hashh[tmp]++;
            }
        }
        ans=0;
        for(int x3=l; x3<=r; ++x3 ){if(!x3)continue;
            for(int x4=l; x4<=r; ++x4 ){if(!x4)continue;
                for(int x5=l; x5<=r; ++x5 ){if(!x5)continue;
                    tmp=maxn+a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;
                    if(tmp>=0&&tmp<=2*maxn&&hashh[tmp]) ans+=hashh[tmp];//判断条件
                }
            }
        }
       // cout<<"23333"<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
