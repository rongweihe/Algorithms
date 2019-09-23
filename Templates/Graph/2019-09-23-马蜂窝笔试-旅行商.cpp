//Create By@herongwei
/*
输入 0,1,2,3#1,0,4,4#5,4,0,2#5,2,2,0
*/
#include <bits/stdc++.h>
using namespace std;

const int inf  = 0x3f3f3f3f;
const int MOD  = 1e9+7;
const int maxn = 1e5 + 233;

int n,m,T,cnt,ans,sum;
int a[maxn],b[maxn];
string s,s1,s2;
double mp[1005][1005];
int dp[1<<11][1005];

void init()     //初始化
{
    for(int i = 0; i < 1005; ++i)
    {
        for(int j = 0; j < 1005; ++j)
        {
            if(i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = mp[j][i] = inf;
        }
    }
}
void flyod()
{
    for(int k=0; k<n; ++k)
    {
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(mp[i][k]+mp[k][j]<mp[i][j])
                {
                    mp[i][j] = mp[i][k]+mp[k][j];
                }
            }
        }
    }
}

int slove(int s,int v)
{
    if(dp[s][v] >= 0)
        return dp[s][v]; //已经有结果
    if(s == (1<<n)-1 && v == 0)
        return dp[s][v] = 0; //访问完所有城市
    int ret = inf;
    //从u到v
    for(int u=0; u<n; ++u)
    {
        if(!((s >> u) & 1)) //判断是否访问过，如果u这一位是0，即没有访问过
            ret = min(ret,slove(s|(1<<u),u)+(int)mp[v][u]);//状态转移
    }
    return dp[s][v] = ret; //记录结果
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>s;
    int num1 = 0;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]=='#')
            num1++;
    }
    vector<double>v;
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
        v.push_back(inter);
        is >> ch;
    }
    cout<<endl;
    int row=num1+1,col=num1+1;
    n = row;
    init();
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            mp[i][j] = v[i*col+j];
            // cout<<"mp[i][j]"<<mp[i][j]<<" ";
        }
    }
    flyod();
    sum = 0;
    memset(dp,-1,sizeof(dp));
    printf("%.1f\n",1.0*slove(0,0));
    return 0;
}
