/*
链接：https://ac.nowcoder.com/acm/contest/924/F
来源：牛客网

题目描述 
Farmer John为了满足奶牛对美的享受而安装了人工湖。矩形的人工湖分成M行N列(1 <= M <= 30; 1 <= N <= 30)的方形小格子。有些格子有美丽的荷叶，有些有岩石，剩下的格子有的只是美丽的蓝色湖水。
Bessie通过从一片荷叶跳到另一片荷叶上来练习芭蕾。它现在正站在一片荷叶上（看输入数据了解具体位置）。它希望通过在荷叶上跳跃来到达另一片荷叶。它既不能跳到水里也不能跳到岩石上。
只有新手才会感到吃惊：Bessie的跳跃有点类似国际象棋中马那样的移动，在一个方向上移动M1(1 <= M1 <= 30)“格”，然后再在斜方向上移动M2 (1 <= M2 <= 30; M1 != M2)格（或者也许在一个方向上移动M2格，然后在斜方向上移动M1格）。Bessie有时可能有多达8中的跳跃选择。
给出池塘的构造以及Bessie跳跃的形式，找出Bessie从一个位置移动到另一个位置所需的最小的跳跃次数。这个跳跃对于所给的测试数据总是可能的。
输入描述:
第 1 行: 四个空格分开的整数： M, N, M1, 和 M2
第 2 至 M+1行: 第i+1行用N个空格分开的整数描述池塘第i行，0表示水，1表示 荷叶，2表示岩石，3表示Bessie现在站的那块荷叶，4表示跳跃的 终点。
输出描述:
第 1 行: 一个整数，是Bessie从一块荷叶跳到另一块荷叶所需的最小的跳跃数。
示例1
输入
复制
4 5 1 2
1 0 1 0 1
3 0 2 0 4
0 1 2 0 0
0 0 0 1 0
输出
复制
2
说明
Bessie在第二行的左边开始；她的目的地在第二行的右边。池塘中有几块荷叶和岩石。
Bessie聪明的跳到了(1,3)的荷叶上，再跳到目的地。
*/

//github.com/rongweihe
//BFS
#include <bits/stdc++.h>
using namespace std;
const int maxn =33;
int mp[maxn][maxn];
struct node
{
    int x,y;
    int step;
} st;
int m,n,m1,m2,step;
int sx,sy,ex,ey;
bool vis[maxn][maxn];
bool check(int x,int y)
{
    return (x>=0&&x<m&&y>=0&&y<n);
}
void bfs(int sx,int sy,int ex,int ey)
{
    int dirx[8]= {-m1,-m1,m1,m1,-m2,-m2,m2,m2};
    int diry[8]= {m2,-m2,m2,-m2,m1,-m1,m1,-m1};
    queue<node> q;
    st.x=sx;
    st.y=sy;
    st.step=0;
    q.push(st);
    vis[sx][sy]=true;
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        //走到终点
        if(now.x==ex&&now.y==ey)
        {
            step=now.step;
            return;
        }
        for(int i=0; i<8; ++i)
        {
            int dx=now.x+dirx[i];
            int dy=now.y+diry[i];
            if(check(dx,dy) && !vis[dx][dy] && (mp[dx][dy]==1||mp[dx][dy]==4))
            {
                node next = now;
                next.x=dx;
                next.y=dy;
                next.step++;
                q.push(next);
                vis[dx][dy]=true;
            }
        }
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&m,&n,&m1,&m2);
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            scanf("%d",&mp[i][j]);
        }
    }
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(mp[i][j]==3)
            {
                sx=i;
                sy=j;
            }
            if(mp[i][j]==4)
            {
                ex=i;
                ey=j;
            }
        }
    }
    bfs(sx,sy,ex,ey);
    printf("%d\n",step);
    return 0;
}

