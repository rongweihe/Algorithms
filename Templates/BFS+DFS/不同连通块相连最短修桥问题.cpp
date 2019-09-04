
/*
codeforces590C
题目链接：http://codeforces.com/problemset/problem/590/C
题目大意：给你一个n*m的图，#代表不同，'.'代表可以修路,数字1,2,3代表属于某个国家……然后让你求三个国家互相连通最少需要修几条路
思路：分别求每个国家到其它国家的最短路，然后枚举中间点，求最短路。

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

#include <bits/stdc++.h>
using namespace std;

const int maxn =  1050;
const int inf  = 0x3fffffff;
const int inff = 9000000;
int n, m;
int dis[3][maxn][maxn];
char mp[maxn][maxn], vis[maxn][maxn];
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
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mp[nx][ny] != '#')
        return true;
    else
        return false;
}

void bfs(int s)
{
    memset(vis, 0,sizeof(vis));
    for(int i = 0 ; i <= n ; ++i)
    {
        for(int j = 0 ; j <= m ; ++j)
        {
            dis[s][i][j] = inff;
        }
    }
    priority_queue<node>Q;
    while(!Q.empty())
        Q.pop();
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < m ; ++j)
        {
            if(mp[i][j] == s + 1 +  '0')
            {
                tmp.x = i ;
                tmp.y = j;
                tmp.d = 0;
                Q.push(tmp);
                dis[s][i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    while(!Q.empty())
    {
        tmp = Q.top();
        Q.pop();
        for(int i = 0 ; i < 4 ; ++i)
        {
            cur.x = tmp.x + dir[i][0];
            cur.y = tmp.y + dir[i][1];
            if(judge(cur.x, cur.y))
            {
                if(mp[cur.x][cur.y] == '.')
                    cur.d = tmp.d + 1;
                else
                    cur.d = tmp.d;
                dis[s][cur.x][cur.y] = tmp.d;
                Q.push(cur);
                vis[cur.x][cur.y] = 1;
            }
        }
    }
}

int main()
{
   // freopen("in.txt","r",stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0 ; i < n ; ++i)
            scanf("%s", mp[i]);
        for(int i=0; i<3; ++i)
            bfs(i);
        int ans = inf;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if(mp[i][j] == '#')
                    continue;
                if(ans > dis[0][i][j] + dis[1][i][j] + dis[2][i][j])
                {
                    ans = dis[0][i][j] + dis[1][i][j] + dis[2][i][j];
                    if(mp[i][j] == '.')
                        ans ++ ;
                }
            }
        }
        if(ans >= inff)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
