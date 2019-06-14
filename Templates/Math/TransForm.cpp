/*
【任务】把一个x进制数转为y进制数
【说明】
先把x进制数转为十进制，如果x进制的数为s=sn-1sn-2...s0则对应的十进制数为Sigma(si*x^i)
,再将其不断取模在倒序，转为y进制数。
【接口】　
string transform(int x,int y,string s);
复杂度：Ｏ(length)
输入：x,y(2<=x,y<=36) s:x进制的数，其中每一位的10~35用A~Z表示。
输出：x进制的数s对应的y进制数，其中每一位的10~35用A~Z表示。

*/

/* ***********************************************
Author        :herongwei
Created Time  :Fri 14 Jul 2017 09:36:23 AM CST
File Name     :hdu-2031.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn  = 533;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);
int n,r;
string transform(int x,int y,string s)
{
    string res = "";
    int sum=0;
    for(int i=0; i<s.length(); ++i)
    {
        if(s[i]=='-') continue;
        if(s[i]>='0'&&s[i]<='9') sum=sum*x+s[i]-'0';
        else sum=sum*x+s[i]-'A'+10;
    }
    //cout<<"sum= "<<sum<<endl;
    while(sum)
    {
        char tp=sum%y;
        sum/=y;
        if(tp<=9) tp+='0'; ///?
        else tp=tp-10+'A';
        res+=tp;
    }
    if(res.length()==0) res="0";
    reverse(res.begin(),res.end());
    if(s[0]=='-') res='-'+res;
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    string s;
    while(cin>>n>>r>>s)
    {
        //char t[maxn];
        //sprintf(t,"%d",n);
        //s=t;
        cout<<transform(n,r,s)<<endl;
    }
    return 0;
}

