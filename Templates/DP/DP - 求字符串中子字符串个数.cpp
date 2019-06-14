
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+233;
int dpQ[maxn];
int dpQA[maxn];
int dpQAQ[maxn];
int main()
{
  //  freopen("in.txt","r",stdin);
    string str;
    while(cin>>str)
    {
        memset(dpQ,0,sizeof(dpQ));
        memset(dpQA,0,sizeof(dpQA));
        memset(dpQAQ,0,sizeof(dpQAQ));
        int len = str.size();
        for(int i=0; i<len; ++i)
        {
            if(str[i]=='A') dpQA[i]=dpQA[i-1]+dpQ[i-1];
            if(str[i]=='Q')
            {
                dpQAQ[i]=dpQAQ[i-1]+dpQA[i-1];
                dpQ[i]=dpQ[i-1]+1;
            }
            if(dpQ[i]==0)dpQ[i]=dpQ[i-1];
            if(dpQA[i]==0)dpQA[i]=dpQA[i-1];
            if(dpQAQ[i]==0)dpQAQ[i]=dpQAQ[i-1];
        }
        int c1=0,c2=0;
       // std::cout<<dpQ[len-1]<<endl;
      //  std::cout<<dpQA[len-1]<<endl;
      //  std::cout<<c1<<endl;
      //  std::cout<<c2<<endl;
       std::cout<<dpQAQ[len-1]<<endl;
       // cout<<endl;
    }
    return 0;
}

/*
int main()
{
  while(cin>>str){
    int len = str.length();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++){
      str[i] = tolower(str[i]);
      dp[1] = (dp[1] + (str[i] == 'c')) % mod;
      dp[2] = (dp[2] + (str[i] == 'w') * dp[1]) % mod;
      dp[3] = (dp[3] + (str[i] == 'b') * dp[2]) % mod;
      dp[4] = (dp[4] + (str[i] == 'c') * dp[3]) % mod;
    }
    cout<<dp[4]<<endl;
  }
  return 0;
}
*/
