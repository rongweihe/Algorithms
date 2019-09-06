#include <bits/stdc++.h>
using namespace std;
int const N = 100 + 10;
int n,k,dp[N][N],sz[N],ans;
vector<int>G[N];
void dfs(int u,int fa){
	sz[u] = 1;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(v == fa)	continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(v == fa)	continue;
		for(int j=sz[u];j>=1;j--){
			for(int k=1;k<j;k++)
				dp[u][j] = max(dp[u][j],dp[u][j-k] + dp[v][k]);
		}
	}
}
int main(){
	while(~scanf("%d%d",&n,&k)){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			scanf("%d",&dp[i][1]);   //直接初始化
		for(int i=0;i<n;i++)	G[i].clear();
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0,-1);
		int ans = 0;
		for(int i=0;i<n;i++)   //遍历每一个点，考虑最大值
			ans = max(ans,dp[i][k]);
		printf("%d\n",ans);
	}
	return 0;
}

/*
5 2 1
1 2
1 3
3 4
3 5
1
2
3
4
5
*/


/*
途家名宿笔试题
第一题：守望者的逃离
守望者，在一座岛上，这座岛很快就会沉下去。到那时，岛上的所有人都会遇难。守望者的跑步速度为
13m/s，以这样的速度是无法逃离荒岛的。庆幸的是守望者拥有法术，可在1s内移动50m,不
过每次使用法术都会消耗魔法值10点。守望者的魔法值恢复的速度为4点/s，只有处在原地
休息状态时才能恢复。
现在已知守望者的魔法初值M，他所在的初始位置与岛的出口之间的距离S,岛沉没的时间T。

你的任务写写一个程序帮助守望者计算如何在最短的时间内逃离荒岛，若不能逃出，则输出守望
者在剩下的时间能走的最远距离。注意：守望者跑步、闪烁或休息活动均以秒(s)为单位，且每
次活动的持续时间为整数秒。距离的单位为米(m)。
————————————————
*/
参考代码

#include <bits/stdc++.h>
using namespace std;
int m,s,t,a,b;
int main()
{
   // freopen("in.txt","r",stdin);
    cin>>m>>s>>t;
    for(int i=1; i<=t; ++i)
    {
        a+=13;
        if(m>=10)
        {
            m-=10;
            b+=50;
        }
        else
            m+=4;
        a=max(a,b);
        if(a>=s)
        {
            cout<<"Yes"<<endl<<i;
            return 0;
        }
    }
    cout<<"No"<<endl<<a;
    return 0;
}

//第二题 求至少访问M个景点的最短路径

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int inf  = 0x3f3f3f3f;
const int maxn = 1e2 + 233;

int n,m,T,cnt,ans,sum;
int a[maxn],vv[maxn];
int mp[maxn][maxn];
int u,v,w,r;
struct edge
{
    int dis[maxn][maxn];
} q, p;
void Add(int u, int v, int w)
{
    p.dis[u][v] = w;
}
void Floyd()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            for (int k = j + 1; k < i; k++)
                if (q.dis[j][k] + p.dis[j][i] + p.dis[i][k] < ans)
                    ans = q.dis[j][k] + p.dis[j][i] + p.dis[i][k];
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (q.dis[j][k] > q.dis[j][i] + q.dis[i][k])
                    q.dis[j][k] = q.dis[j][i] + q.dis[i][k];
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d%d", &n, &m,&r);
    ans = inf;
    for (int i = 0; i < r; i++)
    {
        cin>>vv[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p.dis[i][j] = inf;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        Add(u - 1, v - 1, w);
        Add(v - 1, u - 1, w);
    }
    q = p;
    Floyd();
    sum=0;
    for(int i=0; i<r; ++i)
    {
        sum=max(sum,q.dis[i+1][0]);
    }
    if (ans < inf)
        printf("%d\n", ans-sum);
    return 0;
}
