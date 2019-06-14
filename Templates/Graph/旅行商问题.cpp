/*
Author: github.com/rongweihe
Date  : 2019-04-14
题目描述
小明目前在做一份毕业旅行的规划。打算从北京出发,分别去若干个城市,然后再回到北京,每个城市之间均乘坐高铁,且每个城市只去一次。由于经费有限,希望能够通过合理的路线安排尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱,找到每个城市只访问一次并返回起点的最小车费花销.
输入描述:
城市个数n (1<ns20,包括北京)
城市间的车票价钱n行n列的矩阵m[n][n]
输出描述:
最小车费花销s

/*
input
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
output
13
*/
思路

旅行商问题 & TSP问题：有n个城市，从起点 0 开始游历每一个城市，只访问每个城市一次，最后回到起点，所需要的最短路径是多少？ 
这个属于NP完全问题。最直接的方法就是枚举法，解空间为n个元素的所有排列组合，为(n−1)!(n−1)!。n稍微一大就无法在有限的时间内做出。还有一些模拟退火算法什么的，这个不太了解，有空再去了解下。 
在acm中，对于此问题，n一般都不大，可以运用floyd + 状压dp来做。 
状压dp： 
对于集合的dp 被称为状态压缩dp。对于一个集合来说我们可以把每一个元素是否选取对应到一个二进制数位里，从而将状态压缩成一个整数。 
TSP问题解法： 
考虑使用dp来求解。 
s表示已经经过的城市的集合，v表示现在正处在的城市。定义dp[s][v]为从v出发访问所有剩余的城市，再返回起点所需要的最短的路径。mp[i][j] 表示 i 到 j 的最短路。 
V为所有顶点的集合。初始化dp[V][0] = 0 
状态转移方程：dp[s][v]=min(dp[s|dp[s][v]=min(dp[s|{u}][u]+mp[u][v])][u]+mp[u][v]) (u不属于s) 
集合的表示： 
可以运用上面说的状压dp的方法来做。 
比如 5 个城市，表示成5位二进制数， 对于每一位来说（也就是每一个城市来说）0表示没有访问过，1表示已经访问过。 00000就表示都没有访问过。 
求出mp[i][j] 即任意两点的最短路： 直接 floyd就好了。 
*/

#include <bits/stdc++.h>
using namespace std;
const int N  = 20;
const int INF= 0x3f3f3f3f;
int n;
int mp[N][N];
int dp[1<<11][N];
void floyd(){
    for(int k=0; k<n; ++k){
        for(int i=0;i <n; ++i){
            for(int j=0; j<n; ++j)
                mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
        }
    }
}
//记忆化搜索
int slove(int s,int v) {
    if(dp[s][v] >= 0) return dp[s][v]; //已经有结果
    if(s == (1<<n)-1 && v == 0) return dp[s][v] = 0; //访问完所有城市
    int ret = INF;
    //从u到v
    for(int u=0; u<n; ++u){
        if(!((s >> u) & 1)) //判断是否访问过，如果u这一位是0，即没有访问过
        ret = min(ret,slove(s|(1<<u),u)+mp[v][u]);//状态转移
    }
    return dp[s][v] = ret; //记录结果
}
int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        for(int i = 0;i < n; ++i) fill(mp[i],mp[i]+n,INF);
        for(int i = 0;i < n; ++i){
            for(int j = 0;j <n; ++j)
                scanf("%d",&mp[i][j]);
        }
        floyd();
        memset(dp,-1,sizeof(dp));
        printf("%d\n",slove(0,0));
    }
    return 0;
}


参考博客：https://blog.csdn.net/liujc_/article/details/48373141；https://blog.csdn.net/u013480600/article/details/19692985
