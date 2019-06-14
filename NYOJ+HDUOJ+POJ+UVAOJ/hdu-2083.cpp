/*
hdu-2083 简易版之最短距离

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 19711    Accepted Submission(s): 8886


Problem Description
寒假的时候，ACBOY要去拜访很多朋友，恰巧他所有朋友的家都处在坐标平面的X轴上。ACBOY可以任意选择一个朋友的家开始访问，但是每次访问后他都必须回到出发点，然后才能去访问下一个朋友。
比如有4个朋友，对应的X轴坐标分别为1， 2， 3， 4。当ACBOY选择坐标为2的点做为出发点时，则他最终需要的时间为 |1-2|+|2-2|+|3-2|+|4-2| = 4。
现在给出Ｎ个朋友的坐标，那么ACBOY应该怎么走才会花费时间最少呢？
 

Input
输入首先是一个正整数M，表示M个测试实例。每个实例的输入有2行，首先是一个正整数N（N <= 500)，表示有N个朋友，下一行是N个正整数，表示具体的坐标(所有数据均<=10000).
 

Output
对于每一个测试实例，请输出访问完所有朋友所花的最少时间，每个实例的输出占一行。
 

Sample Input
2
2 
2 4 
3 
2 4 6
 

Sample Output
2
4

*/

/*
【思路】
三位取中，答案ret=min(small,mid,big);
 */ 

/* ***********************************************
Author        :herongwei
Created Time  :Tue 11 Jul 2017 10:58:48 AM CST
File Name     :hdu-2083.cpp
************************************************ */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 533;

inline int read()
{
    int  c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){c=c*10+ch-'0';ch=getchar();}
    return c*f;
}

int t,n,m;
int a[maxn];
int small,mid,big;
long long  s_min,m_min,b_min;

int main()
{
    //freopen("in.txt","r",stdin);
    t=read();
    while(t--)
    {
        s_min=m_min=b_min=0;
        n=read();
        for(int i=1; i<=n; ++i) a[i]=read();
        sort(a+1,a+n+1);
        if(n<=2)
        {
            if(n<=0)
            {
                puts("0");
                continue;
            }
            else
            {
                printf("%lld\n",n==1?a[1]:abs(a[2]-a[1]));
                continue;
            }
        }
        if(n&1)
        {
            small=(n/2);
            mid=small+1;
            big=mid+1;
        }
        else
        {
            mid=(n/2);
            small=mid-1;
            big=mid+1;
        }
        for(int i=1; i<=n; ++i)
        {
            s_min+=abs(a[i]-a[small]);
            m_min+=abs(a[i]-a[mid]);
            b_min+=abs(a[i]-a[big]);
        }
        printf("%lld\n",min(min(s_min,m_min),b_min));
    }
    return 0;
}
