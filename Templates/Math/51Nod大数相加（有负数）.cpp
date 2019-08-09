#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const int N = 10005;
void sum(string a,string b)
{
    int c[N],d[N],ans[N];
    int la=a.length(),lb=b.length();
    for(int i=0;i<la;i++)
        c[i]=a[i]-'0';
    for(int i=0;i<lb;i++)
        d[i]=b[i]-'0';
    reverse(c,c+la);
    reverse(d,d+lb);
    for(int i=0;i<max(la,lb);i++)
    {
        if(c[i]+d[i]>9)
        {
            ans[i]=c[i]+d[i]-10;
            c[i+1]++;
        }
        else ans[i]=c[i]+d[i];
    }
    if(c[max(la,lb)]) cout<<c[max(la,lb)];
    for(int i=max(la,lb)-1;i>=0;i--)
        cout<<ans[i];
    puts("");
}
void sub(string a,string b)
{
    int c[N],d[N],ans[N];
    int la=a.length(),lb=b.length();
    for(int i=0;i<la;i++)
        c[i]=a[i]-'0';
    for(int i=0;i<lb;i++)
        d[i]=b[i]-'0';
    reverse(c,c+la);
    reverse(d,d+lb);
    for(int i=0;i<la;i++)
    {
        if(c[i]>=d[i])
            ans[i]=c[i]-d[i];
        else
        {
            ans[i]=10+c[i]-d[i];
            c[i+1]--;
        }
    }
    int id;
    for(int i=la-1;i>=0;i--)
    {
        if(ans[i])
        {
            id=i;
            break;
        }
    }
    for(int i=id;i>=0;i--)
    {
        cout<<ans[i];
    }
    puts("");
}
int MAX(string a,string b)
{
    if(a.length()==b.length())
        return a>b;
    return a.length()>b.length();
}
int main()
{
    string a,b;
    string c,d;
    cin>>a>>b;
    int la=a.length(),lb=b.length();
    if(a[0]!='-'&&b[0]!='-')
        sum(a,b);
    else if(a[0]=='-'&&b[0]!='-')
    {
        c=a.substr(1,la-1);
        if(MAX(c,b))
        {
            cout<<"-";
            sub(c,b);
        }
        else sub(b,c);
    }
    else if(a[0]=='-'&&b[0]=='-')
    {
        c=a.substr(1,la-1);
        d=b.substr(1,lb-1);
        cout<<"-";
        sum(c,d);
    }
    else
    {
        c=b.substr(1,lb-1);
        if(MAX(a,c))
        {
            sub(a,c);
        }
        else
        {
            cout<<"-";
            sub(c,a);
        }
    }
    return 0;
}
