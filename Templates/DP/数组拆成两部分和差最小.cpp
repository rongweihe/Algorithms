/*
将数组分成两部分，使得这两部分的和的差最小
01 背包变形
这个问题可以转化为求数组的一个子集，使得这个子集中的元素的和尽可能接近sum/2，其中sum为数组中所有元素的和
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf  = 0x3f3f3f3f;
const LL Linf  = 1ll<<61;
const double pi= acos(-1.0);
const int MOD  = 1e9+7;
const int maxn = 1e5 + 233;

//BFS+DFS
int dir4[4][2] = {0,1,0,-1,-1,0,1,0};
int dir8[8][2]= {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
//下，左下，左，左上，上，右上，右，右下

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for ListNode
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};

int n,m,T,cnt,ans,sum;
int a[maxn],b[maxn],dp[maxn];
string s,s1,s2;

int w[maxn],v[maxn];
int W,V;
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n;
    sum=0;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    V = n;
    W = sum/2;
    for(int i=0; i<n; ++i)
    {
        w[i] = a[i];
    }
    for(int i=0; i<n; ++i)
    {
        v[i] = a[i];
    }
    int dp[W+V+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<V; ++i)
    {
        for(int j=W; j>=w[i]; --j)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<abs(sum-2*dp[W])<<endl;
    return 0;
}

