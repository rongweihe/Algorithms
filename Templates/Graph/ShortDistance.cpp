//

```c++
#include <string.h>  
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int N = 105;  
const int INF = 99999999;  
int map[N][N], dist[N];  
bool visit[N];  
int n, m;  
void init()     //初始化  
{  
    int i, j;  
    for(i = 1; i < N; i++)  
    {  
        for(j = 1; j < N; j++)  
        {  
            if(i == j) map[i][j] = 0;  
            else map[i][j] = map[j][i] = INF;  
        }  
    }  
}  
  
void input()    //输入函数  
{  
    int vi, vj, cost;  
    while(m--)  
    {  
        scanf("%d %d %d", &vi, &vj, &cost);  
        if(cost < map[vi][vj])  
            map[vi][vj] = map[vj][vi] = cost;  
    }  
}  
  
void floyd()    //Floyd算法  
{  
    int i, j, k;  
    for(k = 1; k <= n; k++)     //k为中间点  
        for(i = 1; i <= n; i++)  
            for(j = 1; j <= n; j++)  
                if(map[i][k] + map[k][j] <  map[i][j])  
                    map[i][j] = map[i][k] + map[k][j];  
}  
  
void dijkstra()     //Dijkstra算法  
{  
    int i, j, next, MIN;  
    memset(visit, false, sizeof(visit));  
    for(i = 1; i <= n; i++) dist[i] = INF;  
    dist[1] = 0;  
    for(i = 1; i <= n; i++)  
    {  
        MIN = INF;  
        for(j = 1; j <= n; j++)  
            if(!visit[j] && dist[j] <= MIN)  
                MIN = dist[next=j];  
        if(MIN == INF) break;  
        visit[next] = true;  
        for(j = 1; j <= n; j++)  
            if(!visit[j] && dist[j] > dist[next] + map[next][j])  
                dist[j] = dist[next] + map[next][j];  
    }  
}  
  
void spfa()     //SPFA算法  
{  
    int i, now;  
    memset(visit, false, sizeof(visit));  
    for(i = 1; i <= n; i++) dist[i] = INF;  
    dist[1] = 0;  
    queue<int> Q;  
    Q.push(1);  
    visit[1] = true;  
    while(!Q.empty())  
    {  
        now = Q.front();  
        Q.pop();  
        visit[now] = false;  
        for(i = 1; i <= n; i++)  
        {  
            if(dist[i] > dist[now] + map[now][i])  
            {  
                dist[i] = dist[now] + map[now][i];  
                if(visit[i] == 0)  
                {  
                    Q.push(i);  
                    visit[i] = true;  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    while(scanf("%d %d", &n, &m))  
    {  
        if(!n || !m) break;  
        init();  
        input();  
        floyd();  
        //dijkstra();  
        //spfa();  
        printf("%d\n", map[1][n]);  
        //printf("%d\n", dist[n]);  
    }  
    return 0;  
}  
  
测试数据：  
/* 
2 1 
1 2 3 
3 3 
1 2 5 
2 3 5 
3 1 2 
0 0 
*/  
```
