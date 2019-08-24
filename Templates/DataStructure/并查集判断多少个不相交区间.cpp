#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 233;
int n,m,T,a[maxn],b[maxn];

int parent[1002];

int main()
{
    freopen("in.txt","r",stdin);
    int n,m,a,b;
    int count=0;
    scanf("%d %d",&n,&m);
    int list[n+1];
    for(int i=1; i<=n; i++)
    {
        list[i]=i;
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&a,&b);
        while(list[a]!=a)
        {
            a=list[a];
        }
        while(list[b]!=b)
        {
            b=list[b];
        }
        if(list[b]!=list[a])
        {
            list[b]=list[a];
        }
        cout<<"list[a]="<<list[a]<<"list[b]="<<list[b]<<endl;
    }
    /*
    计算最后有多少个不相交的集合
    就算需要多少条边可以成为连通图

    int count = 0; // the number of independent sets

    即计算有多少个 parent[i] == i;

    */
    for(int i=1; i<=n; i++)
    {
        if(list[i]==i)
            count++;
    }
    printf("%d\n",count-1);
}

/**
5 2
1 2
3 5
**/
