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
long long f[maxn][31],dep[maxn];
string str[maxn];
/*
1.倍增法
我们首先脑补一下求LCA的过程——两个节点平层同时往上跳，直到相遇，相遇的点就是他们的LCA。
但是很明显，如果这棵树的深度较大，那么就要跳很久了【这是最最朴素的做法，复杂付O(n*m)】。
所以可以采用倍增优化——大步大步地跳。

我们首先要记录下每个节点的父节点和各个祖先节点，可以开一个fa[maxn][25]，fa[x][i]表示节点x的第i+1位祖先，
也就是说x的父亲节点就是fa[x][0]，爷爷就是fa[x][1]亦是父亲的父亲fa[fa[x][0]][0]……以此类推，
这样在更新的时候我们就可以得到一个递推式：fa[x][i] = fa[fa[x][i - 1]][i - 1].就可以预处理出每个节点的各个祖先。

再者就是——大步大步跳，跳多少呢？明显是（dep为节点深度）。每一次都log一下还要换底（log函数默认底数为e），
所以log我们也打表预处理出来。

在向上跳时，我们先让x和y处于同一层，让深度更深的一个先往上跳，然后两个再一起跳，直到两点有了同一个父亲。
当然，在刚刚得到两点平层的时候可以特判一下：是否两点已经汇合了，是则可以返回了。

参考
链接：https://www.acwing.com/blog/content/212/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
void dfs(long long u,long long fa)
{
    dep[u]=dep[fa]+1;//初始化深度
    for(int i=0; i<=29; ++i) //递推式
    {
        f[u][i+1]=f[f[u][i]][i];
    }
    for(int i=0; i<=26; ++i)
    {
        long long  v = ch[u][i];
        if(!v)
        {
            continue;
        }
        f[v][0]=u;//更新v节点的0好祖先为u
        dfs(v,u);//继续往下遍历
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
    val[pos]=u;//记录此字符串的尾节点
}
long long  LCA(long long  x,long long y)
{
    if(dep[x]<dep[y]) //保证x的深度更大，跳x
        swap(x,y);
    for(int i=30; i>=0; --i)
    {
        if(dep[f[x][i]]>=dep[y]) //让x节点先往上走
            x=f[x][i];
        if(x==y) //保证是同一层
            return x;
    }
    for(int i=30; i>=0; --i)
    {
        if(f[x][i]!=f[y][i])//倍增一起往上跳
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    //cout<<"x===========y="<<x<<y<<endl;//5 8
    cout<<"--------"<<f[x][0]<<endl;
    return f[x][0];
}
int main()
{
    //freopen("in.txt","r",stdin);
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
        long long  ans =LCA(val[a],val[b]);//输出两个节点的最近公共节点
        //cout<<"val[a]="<<val[a]<<val[b]<<endl;
        printf("%lld\n",dep[ans]-1);//输出该公共节点的深度即为最长公共前缀
    }
    return 0;
}

