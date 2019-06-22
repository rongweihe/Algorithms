// github.com/rongweihe
#include <bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("in.txt","r",stdin);
    int x,y,t;
    scanf("%d",&x);
    for(y=0,t=x; t; (y*=10)+=t%10,t/=10);
    cout<<y+x<<endl;
    return 0;
}
