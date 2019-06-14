/*fibonacci*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 233;
const int MOD = 1e9+7;
int fibonacci(int n)
{
    if(n<=1) return n;
    long long fibone=0;
    long long fibtwo=1;
    long long ret=0;
    for(int i=2; i<=n; ++i)
    {
        ret=fibone+fibtwo;
        fibone=fibtwo;
        fibtwo=ret;
    }
    return ret;
}

struct mat
{
    long long m[2][2];
    mat(){memset(m,0,sizeof(m));}
};
mat MultiPly(mat a,mat b)
{
    mat c;
    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            for(int k=0; k<2; ++k)
            {
                c.m[i][j]+=(a.m[i][k]*b.m[k][j])%MOD;
            }
        }
    }
    return c;
}
mat Pow(mat a,long long b)
{
    mat c;
    c.m[0][0]=c.m[1][1]=1;
    while(b)
    {
        if(b&1) c=MultiPly(c,a);
        a=MultiPly(a,a);
        b>>=1;
    }
    return c;
}

long long fibonacci2(long long n)
{
    if(n<=1) return n;
    mat t;
    t.m[0][0]=t.m[0][1]=t.m[1][0]=1;
    t=Pow(t,n-1);
    return t.m[0][0]%MOD;
}
/*Test*/
int main()
{
    for(int i=0; i<=10000; ++i)
    cout<<fibonacci(i)<<endl;
    cout <<fibonacci2(999999) << endl;
    return 0;
}
