#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+233;
int n,m,tot=0,k=0;//n端点总数，m边数，tot记录最终答案，k已经连接了多少边 
int fat[maxn];//记录集体老大 
struct node
{
	int from,to,dis;//结构体储存边 
}edge[200010];
bool cmp(const node &a,const node &b)//sort排序（当然你也可以快排） 
{
	return a.dis<b.dis;
}
int father(int x)//找集体老大，并查集的一部分 
{
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void unionn(int x,int y)//加入团体，并查集的一部分 
{
	fat[father(y)]=father(x);
}
int main()
{
	scanf("%d%d",&n,&m);//输入点数，边数 
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dis);//输入边的信息 
	}
	for(int i=1;i<=n;i++) fat[i]=i;//自己最开始就是自己的老大 （初始化） 
	sort(edge+1,edge+1+m,cmp);//按权值排序（kruskal的体现） 
	for(int i=1;i<=m;i++)//从小到大遍历 
	{
		if(k==n-1) break;//n个点需要n-1条边连接 
		if(father(edge[i].from)!=father(edge[i].to))//假如不在一个团体 
		{
			unionn(edge[i].from,edge[i].to);//加入 
			tot+=edge[i].dis;//记录边权 
			k++;//已连接边数+1 
		}
	}
	printf("%d",tot);
	return 0;
} 
