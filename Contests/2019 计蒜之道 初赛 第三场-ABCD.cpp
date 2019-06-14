//A题
/*
阿里巴巴集团旗下的淘宝已经成为大家最常用的线上购物网站了，小明想买一本算法书，在淘宝浏览选购时发现各家店铺价格有很多。聪明的小明想得到一个价格对比排序，以升序表示。在思考方法时，联想到刚刚上课时学的最长上升子序列知识，心中想到了一个有意思的问题。

如果把这本算法书的 nn 个价格，以 A_1,A_2,\cdots,A_NA1​,A2​,⋯,AN​ 来表示，这就是一个序列了。那如果我们想删除其中一个价格 A_iAi​ 之后，剩下序列的最长上升子序列长度是减少的，那么这样的 A_iAi​ 以多少个呢？

输入格式
第一行为一个整数 NN。 第二行 NN 个整数 A_1,A_2,\cdots,A_NA1​,A2​,⋯,AN​。

输出格式
输出一个整数满足条件的元素个数。

数据范围
数据满足 0 < N \le 100,0 \le A_i \le 10^90<N≤100,0≤Ai​≤109。

样例输入复制

4
1 2 2 3
样例输出复制

2
思路：暴力枚举删除那个位置，看能不能删除这个位置。
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  A[1010],a[1010];
int n;
int solve(int x)
{
    a[0]=-1000;
    int s=0;
    for(int i=1; i<=n; i++)
    {
        if(i==x)
            continue;
        if(A[i]>a[s])
            a[++s]=A[i];
        else
        {
            int l=1,h=s,m;
            while(l<=h)
            {
                m=(l+h)/2;
                if(A[i]>a[m])
                    l=m+1;
                else
                    h=m-1;
            }
            a[l]=A[i];
        }
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
    }
    int ss=solve(0),ans=0;
    for(int i=1; i<=n; i++)
    {
        int d=solve(i);
        if(d!=ss)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
/*
4
1 2 2 3
5
1 4 2 9 10
*/

//B题改成 int 即可 C  题
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
const int  MOD = 1000000000+7;
int PowMod(int a,int b)
{
    int ans = 1;
    a = a % MOD; //对刚进来的a进行取模运算，避免后面第一次求平方运算溢出
    while(b)
    {
        if(b&1) //相当于b % 2 = = 1对二进制下的 b 进行按位与1运算，求二进制下 b 的最低位是否为1
            ans = ans * a % MOD; //对结果进行保存
        b>>=1; //相当于b = b/2;二进制下的 b 右移一位，相当于十进制下的 b 除以2
        a = a * a % MOD;
    }
    return ans;
}
ll qmul(ll x, ll y)   // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法(快速加)
{
    ll ret = 0;
    while(y) {
        if(y & 1)
            ret = (ret + x) % MOD;
        x = x * 2 % MOD;
        y >>= 1;
    }
    return ret;
}
ll qpow(ll a, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n & 1) ret = qmul(ret, a);
        a = qmul(a, a);
        n >>= 1;
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ll n;
    while(scanf("%lld",&n)!=EOF&&n)
    {
        printf("%lld\n",(qpow(4,n-1)%MOD+qpow(2,n-1))%MOD);
    }
    return 0;
}

/*
2019 计蒜之道 初赛 第三场  D题. 阿里巴巴协助征战SARS（困难）
C++ 快速幂取模+大数相乘取模
github.com/rongweihe
*/
#include <bits/stdc++.h>
using namespace std;
#define ll   unsigned long long
const int  MOD = 1000000000+7;
ll qmul(ll x, ll y)   // 乘法防止溢出
{
    ll ret = 0;
    while(y)
    {
        if(y & 1)
            ret = (ret + x) % MOD;
        x = x * 2 % MOD;
        y >>= 1;
    }
    return ret;
}
ll qpow(ll a, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n & 1)
            ret = qmul(ret, a);
        a = qmul(a, a);
        n >>= 1;
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    char n[100001];
    while(cin>>n)
    {
        long long len=strlen(n),t=0,i,ans=1;

        if(len==1&&n[0]=='0')
            return 0;

        for(i=0; i<len; ++i)
        {
            t=(t*10+n[i]-'0')%(MOD-1);
        }
        t--;

        printf("%lld\n",(qpow(4,t)%MOD+qpow(2,t))%MOD);
    }
    return 0;
}

