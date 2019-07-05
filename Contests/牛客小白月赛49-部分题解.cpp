/*
链接：https://ac.nowcoder.com/acm/contest/946/A
来源：牛客网

题目描述 
筱玛是一个热爱地理的好筱玛。最近，在《地理II》作业本上，筱玛学到了“贝塔指数”的概念：

在经济地理学中，交通的联结度表示交通网络的发达程度，通常用贝塔指数来计算与比较。若用
V
V表示一个交通网络中结点的数量，用
E
E表示边的数量，则贝塔指数的计算方式为：
β
=
E
V
β=EV。


“实践是检验真理的唯一标准”。作为一个热爱地理的好筱玛，她马上就把新学的知识应用到实践当中去。筱玛一口气出了
n
n张交通网络规划图，其中第
i
i张交通网络
G
i
Gi有
V
i
Vi个结点和
E
i
Ei条边。筱玛一眼就看出了哪张图好、哪张图坏。但是作为一个负责任的好筱玛，她必须带领同学们一起进步。因此，她需要你将所有的
n
n张图按照贝塔指数排序，并求出它们各自的贝塔指数在模
10
9
+
7
109+7意义下的值。

输入描述:
第一行一个整数
n
n，表示交通网络规划图的数量。

接下来
n
n行，每行两个整数
V
i
Vi和
E
i
Ei，分别表示图
G
i
Gi中的结点数量和边的数量。

输出描述:
输出共
n
n行，每行一个数，表示贝塔指数第
i
i大的交通网络的贝塔指数在模
10
9
+
7
109+7意义下的值。
如果不能整除，输出分数取模后的结果。
示例1
输入
复制
1
1 3
输出
复制
3
说明
显然此时
β
=
E
V
=
3
β=EV=3。
备注:
对于100%的数据，保证
1
≤
n
≤
2
×
10
5
1≤n≤2×105，
1
≤
V
i
,
E
i
≤
10
9
1≤Vi,Ei≤109。


*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+233;
const long long mod=1e9+7;
long long quickpow(long long a, long long b)
{
    if (b < 0)
        return 0;
    long long ret = 1;
    a %= mod;
    while(b)
    {
        if (b & 1)
            ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}
long long inv(long long a)
{
    return quickpow(a, mod - 2);
}
struct node
{
    long long v,e;
    long double p;
    bool operator < ( const node &t) const
    {
        return p>t.p;
    }
}st[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    long long T,n,v,e;
    int len = 0;
    scanf("%lld",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%lld%lld",&e,&v);
        long double p = v/(long double)e;
        st[i].e=e;
        st[i].v=v;
        st[i].p=p;
    }
    sort(st,st+n);
    for(int i=0; i<n; ++i)
    {
        cout<<((st[i].v%mod)*inv(st[i].e))%mod<<endl;
    }
    return 0;
}
