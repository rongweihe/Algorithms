/*
hdu-1999 不可摸数

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 13728    Accepted Submission(s): 3637


Problem Description
s(n)是正整数n的真因子之和，即小于n且整除n的因子和.例如s(12)=1+2+3+4+6=16.如果任何
数m，s(m)都不等于n,则称n为不可摸数.
 

Input
包含多组数据，首先输入T,表示有T组数据.每组数据1行给出n(2<=n<=1000)是整数。
 

Output
如果n是不可摸数，输出yes，否则输出no
 

Sample Input
3
2
5
8
 

Sample Output
yes
yes
no
 

Author
Zhousc@ECJTU

*/

/*i
【思路】  
打表将s(n)的值在1000以内的全部找出来，数组开到100万就行的原因是sqrt（100万）=1000，所以若m大于100万，若它是素数的话s(m)=1，否则s(m)>1000;这样一来s(m)在1000以内的数就全部覆盖了;
核心代码：
77-78行：
j 是i 的倍数，i是j的因子。
*/   

/**************************************************
Author        :herongwei
Created Time  :Fri 07 Jul 2017 02:25:44 PM CST
File Name     :hdu1999.cpp
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
const int maxn  = 1e6+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);

int t, n,m;
bool vis[maxn];
int  a[maxn];
void  init()
{
    for(int i=1; i<=maxn ;++i) vis[i]=false;
    for(int i=1; i< maxn/2; ++i)
        for(int j=2*i; j<maxn; j+=i) a[j]+=i;
    for(int i=2; i<maxn; ++i)
    {
          if(a[i]<=1000)    vis[a[i]]=true;
    }
}
int main()
{
    scanf("%d",&t);
    init();
    while(t--){ 
        scanf("%d",&n);
        if(vis[n]) puts("no");
        else puts("yes");
    } 
    return 0;
} 

