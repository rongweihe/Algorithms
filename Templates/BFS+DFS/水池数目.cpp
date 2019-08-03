/*
Create By herongwei at 2019/08/03
【题目】
南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，
这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。
【思路】：简单的搜索，DFS 或 BFS 注意此时，遇到一个水池，则通过上下左右把相邻区域标记为非水池，最后统计所有水池数目即可
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
            mp[dx][dy]=0;
            dfs(dx,dy);
        }
    }
}

void dfs2(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m && mp[x][y]==1) {
        mp[x][y] = 0;
        dfs2(x+1,y);
        dfs2(x-1,y);
        dfs2(x,y+1);
        dfs2(x,y-1);
    }
    else return;
}
int main() {
    //freopen("in.txt", "r", stdin);
    while(cin>>n>>m) {
        memset(mp,0,sizeof(mp));
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
                    sum++,dfs2(i,j);
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
