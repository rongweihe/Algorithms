/*
题目3 : 检查道路
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
H国有N个城市，编号1~N。城市之间有M条双向高速公路相连，第i条高速公路链接城市Ai和Bi，长度是Ci。  

现在小Hi要乘车从1号城市去N号城市。他一定会选择某条最短路(注意最短路可能有多条)。  

不巧的是，出发前台风登陆，H国大部分地区受到影响，于是小Hi不得不去确认他要走的高速公路是否关闭了。  

由于小Hi一定会选择某条最短路，所以只要某条高速公路处在某条最短路上，他都要确认一下该条高速公路是否关闭。

请你帮小Hi找出他要确认哪些高速公路。

输入
第一行包含两个整数N和M。  

以下M行每行包含3个整数Ai, Bi和Ci，描述第i条高速公路。  

1 <= N <= 1000  

1 <= M <= 1000000  

1 <= Ai, Bi <= N  

0 <= Ci <= 1000

输出
输出M行。

第i行包含YES或者NO表示是否需要检查第i条高速公路。

样例输入
5 7
1 2 1
2 3 1
3 4 1
4 5 1
5 1 3
1 3 2
5 3 1
样例输出
YES
YES
NO
NO
YES
YES
YES
*/

#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
const int maxn = 1011;
int g[maxn][maxn];
int dist1[maxn],distn[maxn];
static bool v[maxn];
void dij(int s,int* dis,int n)
{

    memset(v,0,sizeof v);
    for(int i=1;i<=n;++i)
        dis[i] = inf;
    dis[s] = 0;
    for(int i=1;i<=n;++i)
    {
        int mark=-1,mindis=inf;
        for(int j=1;j<=n;++j)
        {
            if(!v[j]&&dis[j]<mindis)
            {
                mindis=dis[j];
                mark=j;
            }
        }
        v[mark] = 1;
        for(int j=1;j<=n;++j)if(!v[j])
            dis[j]=min(dis[j],dis[mark]+g[mark][j]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> edges;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            g[i][j] = inf;
        }
    }
    for(int i=1;i<=m;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        g[x][y]=g[y][x]=min(g[x][y],c);
        edges.push_back(make_tuple(x,y,c));
    }
    dij(1,dist1,n);
    dij(n,distn,n);
    for(auto e:edges)
    {
        int x,y,c;
        tie(x,y,c) = e;
        if(dist1[x]+c+distn[y] == dist1[n])
            puts("YES");
        else
        if(dist1[y]+c+distn[x] == dist1[n])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
