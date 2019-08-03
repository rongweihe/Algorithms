/*
【题目】
二值图像是由黑白两种像素组成的矩形点阵，图像识别的一个操作是求出图像中最大黑区域的面积。
请设计一个程序完成二值图像的这个操作。黑区域由黑像素组成，一个黑区域中的每个像素至少与该区域中的另一个像素相邻，规定一个像素仅与其上、下、左、右的像素相邻。
两个不同的黑区域没有相邻的像素。一个黑区域的面积是其所包含的像素的个数。
求相应的图像中最大黑区域的面积。
【思路】：简单的搜索，DFS 或 BFS
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+233;
int T,n,m,sum,maxx;
int mp[maxn][maxn];
int dir4[4][2] = {0,1,0,-1,-1,0,1,0};

void dfs(int x, int y) {
    mp[x][y] = 0;
    for(int i=0; i<4; ++i) {
        int dx = x + dir4[i][0];
        int dy = y + dir4[i][1];
        if(dx>=0 && dx<n && dy>=0 && dy<m && mp[dx][dy]==1) {
            ++sum;
            dfs(dx,dy);
        }
    }
}

bool vis[maxn][maxn];
struct node {
    int x,y;
}st[maxn];

void bfs(int x, int y) {
    queue<node> Q;
    node t,next;
    t.x = x;
    t.y = y;

    Q.push(t);
    vis[x][y]=true;
    sum++;

    while(!Q.empty()) {
        t = Q.front();
        Q.pop();

        for(int i=0; i<4; ++i) {
            int dx = t.x + dir4[i][0];
            int dy = t.y + dir4[i][1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && mp[dx][dy]==1 && !vis[dx][dy]) {
                ++sum;
                vis[dx][dy] = true;
                next.x = dx;
                next.y = dy;
                Q.push(next);
            }
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    cin>>n>>m;
    sum=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>mp[i][j];
        }
    }
    maxx=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[i][j]) {
                //sum=0,bfs(i,j),maxx = max(maxx,sum);
                sum=1,dfs(i,j),maxx = max(maxx,sum);
            }
        }
    }
    cout<<maxx<<endl;
    return 0;
}
