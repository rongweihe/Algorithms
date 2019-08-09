/*
https://cn.vjudge.net/problem/SCU-4610

Time Limit: 1000 MS Memory Limit: 32726 K

Description
A: int的大小是有极限的，我从短暂的生命周期中学到一件事情，即使是long long int也只有64位，除非超越int。 
B: 你到底想说什么？ 
A: 我不做int了！

Input
输入包含多个测试用例，每组测试用例为2个不超过1000位的16进制整数。

Output
每行输出一个测试用例的结果，输出它们的和。

Sample Input
1 
111 222

Sample Output
333
*/

//github.com/rongweihe
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char a[maxn],b[maxn],c[maxn];
int d[maxn],e[maxn],f[maxn];
int T,n,m;
int main()
{
   // freopen("in.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        scanf("%s %s",a,b);
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        memset(f,0,sizeof(f));

        int sa=strlen(a);
        int sb=strlen(b);
        int len=0;
        for(int i=sa-1,j=0; i>=0; --i,++j)
        {
            if(a[i]>='0'&&a[i]<='9')
                d[j]=a[i]-48;
            else if(a[i]>='A'&&a[i]<='F')
                d[j]=a[i]-55;
        }
        for(int i=sb-1,j=0; i>=0; --i,++j)
        {
            if(b[i]>='0'&&b[i]<='9')
                e[j]=b[i]-48;
            else if(b[i]>='A'&&b[i]<='F')
                e[j]=b[i]-55;
        }
        if(sa>sb)
            len=sa;
        else
            len=sb;
        for(int i=0; i<len; ++i)
        {
            f[i]=d[i]+e[i];
            if(f[i]>=16)
            {
                f[i]=f[i]%16;
                f[i+1]++;
            }
        }
        for(int i=0; i<=len; ++i)
        {
            if(f[i]>=0&&f[i]<=9)
                c[i]=f[i]+48;
            else if(f[i]>=10&&f[i]<=15)
                c[i]=f[i]+55;
        }
        if(f[len]!=0)
            printf("%c",c[len]);
        for(int i=len-1; i>=0; --i)
            printf("%c",c[i]);
        printf("\n");
    }
    return 0;
}
