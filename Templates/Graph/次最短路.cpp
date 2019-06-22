/*
题目链接：
https://cn.vjudge.net/problem/LightOJ-1099
*/

#include <bits/stdc++.h>
using namespace std;
const int inf =  0xfffffff;
const int maxn = 5000+233;
int n,m,ans,ret,dis1[maxn],dis2[maxn];
bool vis[maxn];
struct Edge
{
    int to;
    int cost;
    Edge(int _to=0,int _cost=0):to(_to),cost(_cost) {}
};
vector<Edge> edge[maxn];
typedef pair<int,int> pii;//first是最短距离，second是顶点编号
int Dij()
{
    priority_queue<pii,vector<pii>,greater<pii> >Q;
    for(int i=0; i<=n; ++i)
    {
        dis1[i]=inf;
        dis2[i]=inf;
    }
    dis1[1]=0;//起点
    Q.push(pii(0,1));//
    while(!Q.empty())
    {
        pii q = Q.top();
        Q.pop();

        int d = q.first;
        int v = q.second;
        if(d>dis2[v])
            continue;
        for(int i=0; i<edge[v].size(); ++i)
        {
            Edge e = edge[v][i];
            int d2 = d+e.cost;
            if(dis1[e.to]>d2)
            {
                swap(dis1[e.to],d2);//!!!!swap交换而不是替换
                Q.push(pii(dis1[e.to],e.to));
            }
            if(dis2[e.to]>d2 && dis1[e.to]<d2)
            {
                dis2[e.to] = d2;
                Q.push(pii(dis2[e.to],e.to));
            }
        }
    }
    return dis2[n];
}
void add_edge(int u,int v,int w)
{
    edge[u].push_back(Edge(v,w));
    edge[v].push_back(Edge(u,w));
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; ++i)
        edge[i].clear();
    int u,v,cost;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&u,&v,&cost);
        add_edge(u,v,cost);
    }
    printf("%d\n",Dij());
    return 0;
}
