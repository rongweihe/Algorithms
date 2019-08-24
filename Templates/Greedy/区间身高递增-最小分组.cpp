#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
int n,m,k,T;
int ans;
int a[maxn],b[maxn];
int sum[maxn];
int fa[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    ans = 0;
    int val=0;
    std::map<int,int>mp;
    for(int i=0; i<n; ++i)
    {
        if(mp.find(a[i])!=mp.end())
        {
            cout<<"find == a[i]="<<a[i]<<endl;
            val= mp[a[i]] + 1;
            if(val==0)
            {
                mp.erase(a[i]);
            }
            else
            {
                mp.insert(pair<int,int>(a[i],val));
            }
        }
        else
        {
            cout<<"a插入"<<a[i]<<endl;
            mp.insert(pair<int,int>(a[i],1));
        }
        if(mp.find(b[i])!=mp.end())
        {
            cout<<"find == b[i]="<<b[i]<<endl;
            val= mp[b[i]] - 1;
            if(val==0)
            {
                mp.erase(b[i]);
            }
            else
            {
                mp.insert(pair<int,int>(b[i],val));
            }
        }
        else
        {
            cout<<"b插入"<<b[i]<<endl;
            mp.insert(pair<int,int>(b[i],-1));
        }
        if(mp.size() ==0 )
        {
            cout<<"size==0"<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
补充样例
输入样例2
10
69079936 236011312 77957850 653604087 443890802 277126428 755625552 768751840 993860213 882053548
输出样例2
6

此时分组为：【69079936】【236011312 77957850】【653604087 443890802 277126428】 【755625552】 【768751840】【 993860213 882053548】调整顺序后即可满足条件

4
2 1 3 2
2
*/
