// Create by @herongwei at 2019/08/05
/*
第二题：多重背包
【描述】
第一行输入两个整数N,M分别代表零食种类数和钱数。
接下来的N行，每行输入三个整数ai, bi, ci(1 <= i <= N) ，代表零食的价格、零食的满意度、零食的数量
输出：求出最大满意度
case:input
2 100
1 1 1
1 1 1
3 100
26 100 4
5 1 4
5 2 2
output
2
306
【思路】：
可以采取一种技巧性地拆分，将原数量为 n 的物品拆分为若干组，每组物品看成一件物品，
其价值和重量为该组中所有物品的价值重量总和，每组物品包含的原物品个数分别为：
1、2、4、……n-2^c+1, 其中 c 为使 n-2^c+1 大于 0 的最大整数。
这种类似于二进制的拆分，不仅可以将物品数量大大降低，
同时通过对这些若干原物品组合得到的新物品的不同组合，
可以得到 0 到 n 之间任意件物品的价值重量和。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+233;
int n,m,T,sum;
struct node
{
    int p; // 零食的价格
    int t; //零食的满意度
}st[maxn];
int dp[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n>>m)
    {
        int index=0,c;
        int price,taste,num;
        for(int i=0; i<n; i++)
        {
            cin>>price>>taste>>num;
            c = 1;
            while( num-c>0 )
            {
                num -= c;
                st[++index].p = c*price;
                st[index].t = c*taste;
                c *= 2;
            }
            st[++index].p = price*num;  //补充不足指数的差值
            st[index].t = taste*num;
        }
        for(int i=0; i<=m; ++i)
            dp[i]=0;
        for(int i=1; i<=index; ++i)   //对拆分后的物品进行0-1背包
        {
            for(int j=m; j>=st[i].p; --j)
                dp[j] = max(dp[j],dp[j-st[i].p]+st[i].t);
        }
        //printf("%d\n",dp[m]);
    }
    return 0;
}

/*
第三题，简单的最短路，看下数据不大，用的简单的 Floyd算法 就可以过（AC）
*/
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
const int INF = 99999999;
int map[maxn][maxn], dist[maxn];
bool visit[maxn];
int N,P,C;
void init()     //初始化
{
    int i, j;
    for(i = 0; i < maxn; i++)
    {
        for(j = 0; j < maxn; j++)
        {
            if(i == j)
                map[i][j] = 0;
            else
                map[i][j] = map[j][i] = INF;
        }
    }
}

void input()    //输入函数
{
    int vi, vj, cost;
    while(P--)
    {
        scanf("%d %d %d", &vi, &vj, &cost);
        if(cost < map[vi][vj])
            map[vi][vj] = map[vj][vi] = cost;
    }
}

void floyd()    //Floyd算法
{
    int i, j, k;
    for(k = 0; k <=N; k++)     //k为中间点
        for(i = 0; i <= N; i++)
            for(j = 0; j <= N; j++)
                if(map[i][k] + map[k][j] <  map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
}
int main()
{
  // freopen("in.txt","r",stdin);
    while(cin>>N>>P>>C)
    {
        init();
        input();
        floyd();
        int sum = 0;
        for(int i=0; i<C; ++i)
        {
            int v;cin>>v;
            sum+=map[0][v];
        }
        printf("%d\n", sum);
    }
    return 0;
}
