/*
处理字符数组
每次记得清空dp数组
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 333;
char mat[maxn][maxn];
int T,n,m;
int main()
{
   // freopen("in.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0; i<n; ++i)
        {
            scanf("%s",mat[i]);
        }
        int res=0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; ++i)
        {
            if(mat[i][0]=='.')
            {
                dp[i][0]=1;
                res=1;
            }
        }
        for(int j=0; j<m; ++j)
        {
            if(mat[0][j]=='.')
            {
                dp[0][j]=1;
                res=1;
            }
        }
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<m; ++j)
            {
                if(mat[i][j]=='.')
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    res=max(dp[i][j],res);
                }
            }
        }
        cout<<res*res<<endl;
    }
    return 0;
}
