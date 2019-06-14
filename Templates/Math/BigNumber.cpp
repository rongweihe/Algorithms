/* ***********************************************
Author        :herongwei
Created Time  :Thu 13 Jul 2017 05:52:04 PM CST
File Name     :BigNumber.cpp　　
【任务】完成高精度整数的加减乘除以及取模运算　　
【接口】　　
结构体：BigNumber  
成员变量：int d[maxn] d[0]表示当前位数，其余d[i]表示第i位上数（每四位压成一个万进制数位）　　
构造函数：BigNumber(string s) 从字符串s构造　　
成员函数：string toString() 输出为字符串  
重载运算符：+,-,*,/,<,==  
运算过程中和结果都不能包含负数。答案最长长度（maxn-1)/4。除法余数保存在全局变量d里面  

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
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);
const int ten[4]= {1,10,100,1000};
const int maxn  = 1000; ///最大位数
const int bit   = 10000; ///每四位压成一个万进制数位

struct BigNumber
{
    int d[maxn];
    BigNumber (string s)
    {
        int len=s.size();
        d[0]=(len-1)/4+1; /*储存位数*/
      //  cout<<"len "<<len<<endl;
        int i,j,k;
        for(i=1; i<maxn; ++i)d[i]=0;/*初始化*/
        for(i=len-1; i>=0; --i)/*从后往前储存位数*/
        {
            j=(len-i-1)/4+1;
            k=(len-i-1)%4;
            d[j]+=ten[k]*(s[i]-'0');/*第j位保存的数,s="0123456" d[0]=2;*/
       //     cout<<"j= "<<j<<" d[j]= "<<d[j]<<endl;
        }
       // cout<<"d[0]1= "<<d[0]<<endl;
        while(d[0]>1 && d[d[0]]==0) --d[0];
       // cout<<"d[0]2= "<<d[0]<<endl;
    }
    BigNumber()
    {
        *this=BigNumber(string("0"));
    }
    string toString()
    {
        string s("");/*初始化空串*/
        int i,j,tp;  /*tp存储每隔４位的数*/
        for(i=3; i>=1; --i) if(d[d[0]]>=ten[i]) break;/*处理从前往后第一个不足四位数*/
        // cout<<"i= "<<i<<endl;
        tp=d[d[0]];
        //  cout<<"tp= "<<tp<<endl;
        for(j=i; j>=0; --j) /*数字转字符串*/
        {
            s=s+(char)(tp/ten[j]+'0');
            tp%=ten[j];
        }
        //cout<<"s1= "<<s<<endl;
        for(i=d[0]-1; i>0; --i)/*以此处理后面的四位数*/
        {
            tp=d[i];
            for(j=3; j>=0; --j)
            {
                s=s+(char)(tp/ten[j]+'0');
                tp%=ten[j];
            }
        }
        //cout<<"s2= "<<s<<endl;
        return s;
    }
} zero("0"),dd,tp,mid[233];

bool operator < (const BigNumber &a,const BigNumber &b)
{
    if(a.d[0]!=b.d[0]) return a.d[0]<b.d[0];
    int i;
    for(i=a.d[0]; i>0; --i) if(a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
    return false;
}

BigNumber operator + (const BigNumber &a,const BigNumber &b)/*大数与大数相加*/
{
    BigNumber c;
    c.d[0]=max(a.d[0],b.d[0]); ///以最大位为基准 cout<<"c.d[0]= "<<c.d[0]<<endl;
    int i,x=0;
    for(i=1; i<=c.d[0]; ++i)
    {
        x+=a.d[i]+b.d[i];      ///cout<<"x= "<<x<<endl;
        c.d[i]=x%bit;          ///cout<<i<<" "<<c.d[i]<<endl;
        x/=bit;
    }
    while(x!=0)/*进位处理*/
    {
        c.d[++c.d[0]]=x%bit;
        x/=bit;
    }
    return c;
}

BigNumber operator -(const BigNumber &a,const BigNumber &b)/*大数与大数相减*/
{
    BigNumber c;
    c.d[0]=a.d[0];
    int i,x=0;
    for(i=1; i<=c.d[0]; ++i)
    {
        x=bit+x+a.d[i]-b.d[i];
        c.d[i]=x%bit;
        x=x/bit-1;///?
    }
    while((c.d[0]>1)&&(c.d[c.d[0]]==0)) --c.d[0];
    return c;
}

BigNumber operator * (const BigNumber &a,const BigNumber &b)/*大数与大数相乘*/
{
    BigNumber c;
    c.d[0]=a.d[0]+b.d[0];///乘积的位数是两个数位数相加cout<<"c.d[0]= "<<c.d[0]<<endl;
    int i,j,x;
    for(i=1; i<=a.d[0]; ++i)/*两个四位数的数相乘*/
    {
        x=0;
        for(j=1; j<=b.d[0]; ++j)
        {
            x=x+a.d[i]*b.d[j]+c.d[i+j-1];///从后往前依次计算４位数　cout<<"x1= "<<x<<endl;
            c.d[i+j-1]=x%bit;///cout<<"i+j-1= "<<i+j-1<< "c.d[i+j-1]= "<<c.d[i+j-1]<<endl;
            x/=bit;
        }
        c.d[i+b.d[0]]=x;/*更新位数*/
        ///cout<<"i= "<<i<<" c.d[i+b.d[0]]= "<<c.d[i+b.d[0]]<<endl;
    }
    while((c.d[0]>1)&& (c.d[c.d[0]]==0)) --c.d[0];
    return c;
}
BigNumber operator * (const BigNumber &a,const int &k)/*大数与整数相乘*/
{
    BigNumber c;
    c.d[0]=a.d[0];
    int i,x=0;
    for(i=1; i<=a.d[0]; ++i)
    {
        x=a.d[i]*k+x;
        c.d[i]=x%bit;
        x/=bit;
    }
    while(x>0)
    {
        c.d[++c.d[0]]=x%bit;
        x/=bit;
    }
    while((c.d[0]>1)&& (c.d[c.d[0]]==0)) --c.d[0];
    return c;
}
bool smaller(const BigNumber &a,const BigNumber &b,int delta)
{
    if((a.d[0]+delta)!=b.d[0]) return (a.d[0]+delta)<b.d[0];
    int i,j;
    for(i=a.d[0]; i>0; --i)if(a.d[i]!=(b.d[i+delta])) return a.d[i]<(b.d[i+delta]);
    return true;
}
void Minus(BigNumber &a,const BigNumber &b,int delta)
{
    int i,x=0;
    for(i=1; i<=a.d[0]-delta; ++i)
    {
        x=x+bit+a.d[i+delta]-b.d[i];
        a.d[i+delta]=x%bit;
        x/=bit-1;
    }
    while((a.d[0]>1)&& (a.d[a.d[0]]==0)) --a.d[0];
}
BigNumber operator /(const BigNumber &a,const BigNumber &b)/*大数与大数相除*/
{
    BigNumber c;
    dd=a;
    int i,j,tp;
    mid[0]=b;
    for(i=1; i<=13; ++i)
    {
        mid[i]=mid[i-1]*2;
    }
    for(i=a.d[0]-b.d[0]; i>=0; --i)
    {
        tp=8192;
        for(j=13; j>=0; --j)
        {
            if(smaller(mid[j],dd,i))
            {
                Minus(dd,mid[j],i);
                c.d[i+1]+=tp;
            }
            tp/=2;
        }
    }
    c.d[0]=max(1,a.d[0]-b.d[0]+1);
    while((c.d[0]>1)&& (c.d[c.d[0]]==0)) --c.d[0];
    return c;
}
bool operator == (const BigNumber &a,const BigNumber &b)/*判断大数与大数相同*/
{
    int i;
    if(a.d[0]!=b.d[0]) return false;
    for(i=1; i<=a.d[0]; ++i) if(a.d[i]!=b.d[i]) return false;
    return true;
}
int main()
{
    // freopen("in.txt","r",stdin);
    BigNumber a("244");
    BigNumber b("6");
    BigNumber c= a/b;
    cout<<c.toString()<<endl;
    //BigNumber c=a+b;
    //cout<<c.toString()<<endl;
    //c=a+b;
    // cout << "Hello world!" << endl;
    return 0;
}





