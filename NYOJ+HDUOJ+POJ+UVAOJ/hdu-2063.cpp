/*
hdu-2063-过山车
Problem Description
RPG girls今天和大家一起去游乐场玩，终于可以坐上梦寐以求的过山车了。可是，过山车的每一排只有两个座位，而且还有条不成文的规矩，就是每个女生必须找个个男生做partner和她同坐。但是，每个女孩都有各自的想法，举个例子把，Rabbit只愿意和XHD或PQK做partner，Grass只愿意和linle或LL做partner，PrincessSnow愿意和水域浪子或伪酷儿做partner。考虑到经费问题，boss刘决定只让找到partner的人去坐过山车，其他的人，嘿嘿，就站在下面看着吧。聪明的Acmer，你可以帮忙算算最多有多少对组合可以坐上过山车吗？
 

Input
输入数据的第一行是三个整数K , M , N，分别表示可能的组合数目，女生的人数，男生的人数。0<K<=1000
1<=N 和M<=500.接下来的K行，每行有两个数，分别表示女生Ai愿意和男生Bj做partner。最后一个0结束输入。
 

Output
对于每组数据，输出一个整数，表示可以坐上过山车的最多组合数。
 

Sample Input
6 3 3
1 1
1 2
1 3
2 1
2 3
3 1
0
 

Sample Output
3

*/

/* ***********************************************
Author        :herongwei
Created Time  :Thu 13 Jul 2017 09:27:23 AM CST
File Name     :hdu-2063.cpp
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
int line[maxn][maxn];
int from[maxn],tot;
bool use[maxn];
int t,boy,girl,K,n,m,k;
bool match(int x)
{
    for(int i=1; i<=boy; ++i)
    {
        if(line[x][i]&&!use[i])///判断当前一对是否匹配以及当前ｂｏｙ是否匹配
        {
            use[i]=true;
            if(from[i]==0 || match(from[i]))///from[i]最大匹配中与左边点i相连的边,且递归判断匹配。
            {
                from[i]=x;
                return true;
            }
        }
    }
    return false;
}
int hungary(int girl)
{
    tot = 0;
    for(int i=1; i<=girl; ++i)
    {
        memset(use,0,sizeof(use));
        if(match(i)) ++tot; ///统计匹配的个数
    }
    return tot;
}

inline int read()
{
    int  c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){ c=c*10+ch-'0'; ch=getchar();}
    return c*f;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&K,&girl,&boy)==3&&K)
    {
        memset(line,0,sizeof(line));
        memset(from,0,sizeof(from));
        for(int i=1; i<=K; ++i)
        {
            n=read();m=read();line[n][m]=1; ///n,m之间连线
        }
       printf("%d\n",hungary(girl));
    }
    return 0;
}

