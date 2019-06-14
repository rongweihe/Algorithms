//github.com/rongweihe
/*
这道题.
给出一个矩阵.求最大子矩阵和. 
举例:51Nod 1051

3 3
-1 3 -1
2 -1 3
-3 1 2
这个样例答案是7.

首先对于每一列都求一下前缀和.
然后我们n^2枚举两行.接下来把这两行之间夹的每一列的和求出来,差分减一下就可以了.
这样做有什么用呢？神奇的事情发生了.算出来的每一列的和变成了一条一维的数,可以用最大子段和的思想算出最大值.
对于所有情况算出最大的结果即可.代码如下,复杂度O(n^3).
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+233;
int a[maxn][maxn];
int n,m,L,R;
void init()
{
    scanf("%d%d",&m,&n);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            int v;
            scanf("%d",&v);
            a[i][j]=a[i-1][j]+v;//求列的前缀和
        }
    }
}
int maxSubSum()
{
    long long ans=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=i; j<=n; ++j)//枚举两行
        {
            long long sum=0;
            for(int k=1; k<=m; ++k)
            {
                sum+=(a[j][k] - a[i-1][k]);//这两行之间所夹的列的和.
                if(sum<0)
                    sum=0;
                ans=max(ans,sum);
            }
        }
    }
    return ans;
}
int main()
{
    // freopen("in.txt","r",stdin);
    init();
    long long ans = maxSubSum();
    printf("%lld\n",ans);
    return 0;
}
