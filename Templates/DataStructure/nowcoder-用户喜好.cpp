【链接】https://www.nowcoder.com/questionTerminal/e9d0a72fb08044efb8263946f405ec4b?orderByHotValue=0&questionTypes=000100&page=1&onlyReference=false
来源：牛客网

【problem】为了不断优化推荐效果，今日头条每天要存储和处理海量数据。
假设有这样一种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，
每个用户都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户）中，
有多少用户对这类文章喜好值为k。因为一些特殊的原因，不会出现一个查询的用户区间完全覆盖另一个查询的用户区间(不存在L1<=L2<=R2<=R1)。



输入描述:
输入： 第1行为n代表用户的个数 第2行为n个整数，
第i个代表用户标号为i的用户对某类文章的喜好度 
第3行为一个正整数q代表查询的组数  
第4行到第（3+q）行，每行包含3个整数l,r,k代表一组查询，即标号为l<=i<=r的用户中对这类文章喜好值为k的用户的个数。
数据范围n <= 300000,q<=300000 k是整型


输出描述:
输出：一共q行，每行一个整数代表喜好值为k的用户的个数
示例1
输入
5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3
输出
1
0
2
说明
样例解释:
有5个用户，喜好值为分别为1、2、3、3、5，
第一组询问对于标号[1,2]的用户喜好值为1的用户的个数是1
第二组询问对于标号[2,4]的用户喜好值为5的用户的个数是0
第三组询问对于标号[3,5]的用户喜好值为3的用户的个数是2

【solution】
/*
一开始以为要用线段树这些复杂数据结构？是不是数据比较水？
用一个结构体保存每个用户的编号和喜好度，然后对用户按喜好度升序排序（喜好度相同的按序号升序排序）
用一个map记录每一个喜好度开头的第一个用户在排序后序列中的位置，
对于每一次查询，直接找到第一个喜好度为k的用户在序列中的位置，
然后看用户的序号是不是在l和r之间，如果喜好度不为k或者序号大于了r，
查询结束，输出结果。
Author：herongwei
Data:  2018/03/04 Sun
*/

#include <iostream>
#include <initializer_list>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000+233;

int t,n,m,q,k;
set<int,int>Set;
map<int,int>mp; //map用来记录 喜好度，位置
struct node
{
    int id;
    int like;
} st[maxn];
bool cmp(node &a,node &b) //排序规则
{
    if(a.like==b.like) return a.id<=b.id;
    else  return a.like<=b.like;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; ++i)
        {
            int k;
            scanf("%d",&k);
            st[i].id=i;
            st[i].like=k;
        }
        /*
        std::multiset<int>::iterator it;
        for(it=Set.begin(); it!=Set.end(); ++it)
            std::cout << ' ' << *it;
        */
        sort(st,st+n,cmp); //复杂度O(nlogn)
        mp[st[0].like]=0;
        for(int i=1; i<n; ++i) //去重
        {
            if(st[i].like!=st[i-1].like)
            {
                mp[st[i].like]=i;
            }
        }
        /*
                std::map<int,int>::iterator it;
                for (it=mp.begin(); it!=mp.end(); ++it)
                    std::cout << it->first << " => " << it->second << '\n';

                for(int i=1; i<=n; ++i)
                {
                    printf("%d %d\n",st[i].id,st[i].like);
                }
        */
        scanf("%d",&q);
        int sum;
        while(q--) //查询
        {
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);l--;r--;
            sum=0;
            for(int i=mp[v]; i<n; ++i) //按照喜好度的位置来查询 这里貌似复杂度是O(n)
            {
                if(st[i].like!=v || st[i].id>r)break;  //但是这里进行了判断
                if(st[i].id>=l && st[i].id<=r) sum++;
            }
            printf("%d\n",sum);
        }
    }return 0
