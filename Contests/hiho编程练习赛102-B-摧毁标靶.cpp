/*
题目 2 : 摧毁标靶
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
在无限大的XY平面上有N个标靶，其中第i个的位置在(Xi, Yi)。此外平面上还有M个炸弹，其中第i个的位置在(Xi, Yi)。一旦引爆，这枚炸弹可以摧毁所有与它在同一横坐标或同一纵坐标上、距离它不超过Di的所有标靶。  

假设我们引爆了所有的炸弹，请你计算一共会有多少个标靶被摧毁。

输入
第一行包含两个整数N和M。  

以下N行每行包含两个整数Xi和Yi，描述一个标靶的位置。

再以下M行每行3个包含整数Xi, Yi和Di，描述一个炸弹的位置和范围。  

对于50%的数据，1 <= N, M <= 10000  

对于100%的数据，1 <= N, M <= 100000  -1000000000 <= Xi, Yi, Di <= 1000000000

输出
一个整数代表答案

样例输入
3 1
0 0  
1 0   
0 1  
1 1 10
样例输出
2
*/



#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAX=1e5+10;
const double PI=acos(-1.0);
typedef long long ll;
struct Point
{
    int x,y,d;
    int index;
}A[MAX],B[MAX];
int n,m;
int cmpx(const Point &p,const Point&q)
{
    if(p.x==q.x)return p.y<q.y;
    return p.x<q.x;
}
int cmpy(const Point &p,const Point&q)
{
    if(p.y==q.y)return p.x<q.x;
    return p.y<q.y;
}
pair<int,int> fx(int x)
{
    int l=1,r=n;
    pair<int,int>t=make_pair(-1,-1);
    while(r>=l)
    {
        int mid=(l+r)/2;
        if(A[mid].x>x)r=mid-1;
        else
        {
            l=mid+1;
            if(A[mid].x==x)t.second=mid;
        }
    }
    l=1,r=n;
    while(r>=l)
    {
        int mid=(l+r)/2;
        if(A[mid].x<x)l=mid+1;
        else
        {
            r=mid-1;
            if(A[mid].x==x)t.first=mid;
        }
    }
    return t;
}
pair<int,int> fy(int y)
{
    int l=1,r=n;
    pair<int,int>t=make_pair(-1,-1);
    while(r>=l)
    {
        int mid=(l+r)/2;
        if(A[mid].y>y)r=mid-1;
        else
        {
            l=mid+1;
            if(A[mid].y==y)t.second=mid;
        }
    }
    l=1,r=n;
    while(r>=l)
    {
        int mid=(l+r)/2;
        if(A[mid].y<y)l=mid+1;
        else
        {
            r=mid-1;
            if(A[mid].y==y)t.first=mid;
        }
    }
    return t;
}
int p[MAX];
int v[MAX];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d%d",&A[i].x,&A[i].y),A[i].index=i;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].d);
    sort(A+1,A+n+1,cmpx);
    for(int i=1;i<=m;i++)
    {
        pair<int,int>t=fx(B[i].x);
        if(t.first==-1)continue;
        //printf("[%d,%d]\n",t.first,t.second);
        int L=n,R=0;
        int l=t.first,r=t.second;
        while(r>=l)
        {
            int mid=(l+r)/2;
            if(A[mid].y<B[i].y-B[i].d)l=mid+1;
            else r=mid-1,L=mid;
        }
        l=t.first,r=t.second;
        while(r>=l)
        {
            int mid=(l+r)/2;
            if(A[mid].y>B[i].y+B[i].d)r=mid-1;
            else l=mid+1,R=mid;
        }
        //printf("L=%d R=%d\n",L,R);
        if(R<L)continue;
        p[L]++;
        p[R+1]--;
    }
    for(int i=1;i<=n;i++)p[i]+=p[i-1];
    for(int i=1;i<=n;i++)if(p[i])v[A[i].index]=1;
    memset(p,0,sizeof p);
    sort(A+1,A+n+1,cmpy);
    for(int i=1;i<=m;i++)
    {
        pair<int,int>t=fy(B[i].y);
        if(t.first==-1)continue;
        int L=n,R=0;
        int l=t.first,r=t.second;
        while(r>=l)
        {
            int mid=(l+r)/2;
            if(A[mid].x<B[i].x-B[i].d)l=mid+1;
            else r=mid-1,L=mid;
        }
        l=t.first,r=t.second;
        while(r>=l)
        {
            int mid=(l+r)/2;
            if(A[mid].x>B[i].x+B[i].d)r=mid-1;
            else l=mid+1,R=mid;
        }
        if(R<L)continue;
        p[L]++;
        p[R+1]--;
    }
    for(int i=1;i<=n;i++)p[i]+=p[i-1];
    for(int i=1;i<=n;i++)if(p[i])v[A[i].index]=1;
    int ans=0;
    for(int i=1;i<=n;i++)ans+=v[i];
    cout<<ans<<endl;
    return 0;
}
