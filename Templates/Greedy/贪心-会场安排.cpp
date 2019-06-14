/*
会场安排问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
学校的小礼堂每天都会有许多活动，有时间这些活动的计划时间会发生冲突，需要选择出一些活动进行举办。小刘的工作就是安排学校小礼堂的活动，每个时间最多安排一个活动。现在小刘有一些活动计划的时间表，他想尽可能的安排更多的活动，请问他该如何安排。
输入
第一行是一个整型数m(m<100)表示共有m组测试数据。
每组测试数据的第一行是一个整数n(1<n<10000)表示该测试数据共有n个活动。
随后的n行，每行有两个正整数Bi,Ei(0<=Bi,Ei<10000),分别表示第i个活动的起始与结束时间（Bi<=Ei)
输出
对于每一组输入，输出最多能够安排的活动数量。
每组的输出占一行
样例输入
2
2
1 10
10 11
3
1 10
10 11
11 20
样例输出
1
2
提示
注意：如果上一个活动在t时间结束，下一个活动最早应该在t+1时间开始
【分析】贪心法（经典贪心问题：区间选择）
*/

//github.com/rongweihe
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+233;
int ans;
struct Activity
{
    int b;
    int e;
    bool operator < (const Activity &t)
    {
        return (e<t.e);
    }
} st[maxn];
int main()
{
   // freopen("in.txt","r",stdin);
    int n,end;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        int s,e;
        scanf("%d %d",&s,&e);
        st[i].b=s;
        st[i].e=e+s-1;
    }
    sort(st,st+n);
    ans=end=0;
    for(int i=1; i<=n; ++i)   //分析每个活动
    {
        if(st[i].b>end)   //若发现某个活动的开始时间>end
        {
            ans++;       //则选择此活动
            end=st[i].e;  //并更新结束时间
        }
    }
    printf("%d\n",ans);
    return 0;
}
