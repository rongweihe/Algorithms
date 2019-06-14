
/*
Data:2019-04-03
Author: github.com/rongweihe
Solution:
01-knapSack Problem
有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

基本思路

这是最基础的背包问题，特点是：每种物品仅有一件，可以选择放或不放。

用子问题定义状态：即f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。则其状态转移方程便是：

f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}

这个方程非常重要，基本上所有跟背包相关的问题的方程都是由它衍生出来的。所以有必要将它详细解释一下：
“将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），那么就可以转化为一个只牵扯前i-1件物品的问题。
如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”，价值为f[i-1][v]；如果放第i件物品，
那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，此时能获得的最大价值就是f[i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+233;
int w[maxn];
int v[maxn];
int knapSack(int W,int w[],int v[],int n)
{
    int i,j;
    int dp[n+1][W+1];
    for(i=0; i<=n; ++i)
    {
        for(j=0; j<=W; ++j)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(w[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T,n,W;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&W);
        for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
        for(int i=1; i<=n; ++i) scanf("%d",&w[i]);
        printf("%d\n", knapSack(W, w, v, n));
    }
    return 0;
}

/*
Sample input
2
3
4
1 2 3
4 5 1
3
50
60 100 120
10 20 30
Sample output
3
220
*/
