/*
题目1 : 等差数列
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
给定N个整数A1, A2, ... AN，请你从中找出M个整数，组成等差数列。  

那么M最大可能是多少？

输入
第一行包含一个整数N。

以下N行每行一个整数Ai。

1 <= N <= 5000  

0 <= Ai <= 1000000

输出
一个整数代表答案

样例输入
6
0
5
3
1
9
6
样例输出
4
*/

#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAX=5e3+10;
const double PI=acos(-1.0);
typedef long long ll;
int d[MAX][MAX];
int a[MAX];
int p[1000001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    assert(a[n]<=1000000);
    for(int i=1;i<=n;i++)p[a[i]]=i;
    int ans=2;
    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)d[j][i]=2;
    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
    {
        if(2*a[i]-a[j]>1000000||p[2*a[i]-a[j]]==0)continue;
        int k=p[2*a[i]-a[j]];
        d[i][k]=max(d[i][k],d[j][i]+1);
        ans=max(ans,d[i][k]);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])sum++;
        else sum=1;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}

