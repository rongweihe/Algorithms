/*
输入
3 3
40 24 135
200 239 238
90 34 94
卷积层
2
0.0 0.6
0.1 0.3
输出
106 176
162 174
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+233;
int mp[maxn][maxn];
double mm[maxn][maxn];
int main()
{
   // freopen("in.txt","r",stdin);
    int h,w,m;
    cin>>h>>w;
    for(int i=0; i<h; ++i)
    {
        for(int j=0; j<w; ++j)
        {
            cin>>mp[i][j];
        }
    }
    cin>>m;
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>mm[i][j];
        }
    }
    int hh = (h-m+1);
    int ww = (w-m+1);
    double ans[hh+1][ww+1] = {0};
    double t;
    for(int i=0; i<hh; ++i)
    {
        for(int j=0; j<ww; ++j)
        {
            double t=0;
            for(int x=0; x<m; ++x)
                for(int y=0; y<m; ++y)
                    t += mp[i+x][j+y]*mm[x][y];
            t = min(t,255*1.0);
            cout<<"t="<<t<<endl;
            ans[i][j] = floor(t);
        }
    }
    for(int i=0; i<hh; ++i)
    {
        for(int j=0; j<ww; ++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
