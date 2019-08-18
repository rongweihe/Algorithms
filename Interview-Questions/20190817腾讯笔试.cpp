/*
Create By @herongwei 2018/08/17
最小区间覆盖
【情况一】
只要能覆盖长度，超了也行
比如
4 6
3 6
2 4
0 2
4 7
【0,2】，【2,4】，【4,7】也行
【0,2】，【2,4】，【3,6】也行
输出 3
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
const int maxn = 1e5+233;
typedef long long LL;
LL n,m,L;
LL a[maxn];
struct node
{
    LL x, y;
    bool operator < (const struct node& rhs) const
    {
        if (x == rhs.x)
            return y > rhs.y;
        return x < rhs.x;
    }
} st[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>L;
    memset(st,0,sizeof(st));
    for(int i = 0; i < n; ++i)
        cin>>st[i].x>>st[i].y;
    sort(st, st + n);
    if(st[0].x!=0)
        puts("-1");
    LL maxx=0,maxy=0;
    LL ans=0,pox=0;
    int i=0;
    while(i<n)
    {
        // cout<<"maxx11=="<<maxx<<endl;
        //判断当前i区间开始时间大于前一个区间的最大结束时间，会导致时间不连续，直接 break
        if(st[i].x > maxx)
        {
            break;
        }
        //后面每次更新区间即可，当前区间的开始时间小于等于前一个区间的最大值
        maxy = maxx;
        while( i<n && st[i].x<=maxx)
        {
            if(maxy < st[i].y)
            {
                maxy = st[i].y;
            }
            i += 1;
        }
        maxx = maxy;
        ans += 1;
        //最大时间不大于L退出
        if(maxx >= L)
        {
           // cout<<"maxx=="<<maxx<<endl;
            break;
        }
    }
    if(maxx >= L)
        cout<<ans<<endl;
    else
        puts("-1");
    return 0;
}
