/* ***********************************************
Author        :herongwei
Created Time  :08-12 2017 20:53:17 PM CST
File Name     :hdu-6108.cpp

小C的倍数问题

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 334    Accepted Submission(s): 179


Problem Description
根据小学数学的知识，我们知道一个正整数x是3的倍数的条件是x每一位加起来的和是3的倍数。反之，如果一个数每一位加起来是3的倍数，则这个数肯定是3的倍数。

现在给定进制P，求有多少个B满足P进制下，一个正整数是B的倍数的充分必要条件是每一位加起来的和是B的倍数。


Input
第一行一个正整数T表示数据组数(1<=T<=20)。

接下来T行，每行一个正整数P(2 < P < 1e9)，表示一组询问。


Output
对于每组数据输出一行，每一行一个数表示答案。


Sample Input
1
10


Sample Output
3


Source
2017"百度之星"程序设计大赛 - 初赛（A）

[思路]
10进制下，举个例子ab(a是十位数上数，b是个位数数)，满足为B的倍数则有：
a+b=B*k1(每一位上数为B倍数)
10*a+b=B*k2(该数本身为B倍数)
k1,k2为正整数
两式做差得:9a=B(k2-k1)即满足条件B个数为9因子个数。
举一反三P进制下
a+b=B*k1
p*a+b=B*k2
两式做差得:(p-1)a=B(k2-k1)即满足条件B个数为p-1因子个数。
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
const int maxn  = 1e5+2333;
const int MOD   = 1e9+7;
const LL inf   = 0x3f3f3f3f;
const double eps= 1e-8;
const double pi = acos(-1.0);
int n,m,t,tot,cnt,ans,ret,tmp;

inline LL read(){
    int  c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){c=c*10+ch-'0';ch=getchar();}
    return c*f;
}

int get_divsor(int p){
    ret=0;
    for(int i=1; i<=sqrt(p); ++i){
        if(p%i==0){
            ret++;
            if(i*i!=p) ret++;
        }
    }
    return ret;
}

int main(){
   // freopen("in.txt","r",stdin);
    t=read();
    while(t--){
        ret=0;
        int p;
        p=read();
        --p;
        printf("%d\n",get_divsor(p));
    }
    return 0;
}

