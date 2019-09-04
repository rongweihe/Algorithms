/*
codeforces590C
题目链接：http://codeforces.com/problemset/problem/590/C
题目大意：给你一个n*m的图，#代表不同，'.'代表可以修路,数字1,2,3代表属于某个国家……然后让你求三个国家互相连通最少需要修几条路
思路：分别以1,2,3为起点求三遍最短路即可。。因为是二维，用BFS即可。注意队列一定要用优先级，因为你可能走了好几步但是距离还是1，所以用距离作为优先级的标准。然后搜就可以了。

Examples
inputCopy
4 5
11..2
#..22
#.323
.#333
outputCopy
2
inputCopy
1 5
1#2#3
outputCopy
-1
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define maxn 1050
const int inf  = 0x3f3f3f3f;
const int inff = INT_MAX;
int n, m;
int dis[3][maxn][maxn];
char load[maxn][maxn], vis[maxn][maxn];
int dir[][2] = {1, 0, 0, 1, -1, 0, 0,-1};

struct node
{
    int x, y;
    int d;
    bool friend operator<(node n1, node n2)
    {
        return n1.d > n2.d;
    }
} tmp, cur;


bool judge(int nx, int ny)
{
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && load[nx][ny] != '#')
        return true;
    else
        return false;
}

void BFS(int s)
{
    memset(vis, 0,sizeof(vis));
    for(int i = 0 ; i <= n ; i ++)
    {
        for(int j = 0 ; j <= m ; j ++)
        {
            dis[s][i][j] = inff;
        }
    }
    priority_queue<node>q;
    while(!q.empty())
        q.pop();
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            if(load[i][j] == s + 1 +  '0')
            {
                tmp.x = i ;
                tmp.y = j;
                tmp.d = 0;
                q.push(tmp);
                dis[s][i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        tmp = q.top();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            cur.x = tmp.x + dir[i][0];
            cur.y = tmp.y + dir[i][1];
            if(judge(cur.x, cur.y))
            {
                if(load[cur.x][cur.y] == '.')
                    cur.d = tmp.d + 1;
                else
                    cur.d = tmp.d;
                dis[s][cur.x][cur.y] = tmp.d;
                q.push(cur);
                vis[cur.x][cur.y] = 1;
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0 ; i < n ; i ++)
            scanf("%s", load[i]);
        BFS(0);
        BFS(1);
        BFS(2);
        int ans = inf;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(load[i][j] == '#')
                    continue;
                //cout<<"i="<<i<<" "<<"j="<<j<<"dis[0][i][j]="<<dis[0][i][j];
               cout<<dis[0][i][j];
//                if(ans > dis[0][i][j] + dis[1][i][j] + dis[2][i][j])
//                {
//                    ans = dis[0][i][j] + dis[1][i][j] + dis[2][i][j];
//                    if(load[i][j] == '.')
//                        ans ++ ;
//                }
            }
            cout<<endl;
        }
        if(ans == inf)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
