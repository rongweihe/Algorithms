/*
问题描述
给出一些串，多组询问求两个串的最长公共前缀。字符串总长 < 10^6。

输入格式
第一行一个整数n，表示字符串的个数。

接下来n行，每行一个字符串（字符串不含空格）。

第n+2行一个整数m，表示询问总数。

接下来m行，每行两个整数a,b,表示询问第a个字符串和第b个字符串的最长公共前缀的长度。

输出格式
输出共m行，对于每个询问输出最长的公共前缀的长度

输入样例
5
abcdef
abcd
acd
cade
abcdef
4
1 2
2 3
1 5
3 4
输出样例
4
1
6
0
限制与约定
1<= m < 10^6

时间限制：1s

空间限制：256MB
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
long long n,ch[maxn][30],val[maxn],cnt,m;
long long f[maxn][31],pre[maxn];
string str[maxn];
void dfs(long long u,long long fa)
{
    pre[u]=pre[fa]+1;
    for(int i=0; i<=29; ++i)
        f[u][i+1]=f[f[u][i]][i];
    for(int i=0; i<=26; ++i)
    {
        long long  v = ch[u][i];
        if(!v)
        {
            continue;
        }
        f[v][0]=u;
        dfs(v,u);
    }
}
void insertStr(long long  pos)
{
    int len = str[pos].length(),u=0;
    for(int i=0; i<len; ++i)
    {
        int x = str[pos][i]-'a';
        if(!ch[u][x])
        {
            ch[u][x]=++cnt;
        }
        u=ch[u][x];
    }
    val[pos]=u;
}
long long  LCA(long long  x,long long y)
{
    if(pre[x]<pre[y])
        swap(x,y);
    for(int i=30; i>=0; --i)
    {
        if(pre[f[x][i]]>=pre[y])
            x=f[x][i];
        if(x==y)
            return x;
    }
    for(int i=30; i>=0; --i)
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    return f[x][0];
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%lld",&n);
    for(int i=1; i<=n; ++i)
    {
        cin>>str[i];
        insertStr(i);
    }
    dfs(0,-1);
    long long  a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        long long  ans =LCA(val[a],val[b]);
        printf("%d\n",pre[ans]-1);
    }
    return 0;
}
