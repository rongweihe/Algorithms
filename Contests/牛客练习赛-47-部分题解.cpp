/*
描述
链接：https://ac.nowcoder.com/acm/problem/25878
来源：牛客网

题目描述 
子弹上膛的声音，是我唱歌的先兆。
                                                 ——百里守约-朱雀志

小T有一张一共有n个字符串的字符串表，因为小T是神所以他可以任意修改这张表，

因为小T是个强迫症，所以他想方设法的使这些字符不同，

所以现在他进行以下操作Q次:

(1):给字符串表中加入一个字符串s。

(2):给字符串表去重，输出去掉字符串的数量。

由于出题人用win10配的数据，所以读入中会有空行出现，请忽略他们，避免应为这个而WA

注:本系列题不按难度排序哦
输入描述:
第一行两个整数n,Q

后n行每行一个字符串

后Q行每行代表一个操作：

一操作：1 s

二操作：2
输出描述:
对于每个二操作，进行回答。
示例1
输入
复制
4 4
play
the
pubg
game
1 game
1 pubg
2
2
输出
复制
2
0
说明


100
%
 
1
≤
n
,
Q
≤
5
×
10
5
100% 1≤n,Q≤5×105

对于所有输入的字符串长度<=40
*/

//参考代码

//github.com/rongweihe
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;
int main()
{
   // freopen("in.txt","r",stdin);
    int n,q;
    cin>>n>>q;
    int tot=0;
    for(int i=1; i<=n; ++i)
    {
        string s;
        cin>>s;
        if(mp[s]==0)
        {
            mp[s]++;//记录当前字符串，累加出现的次数
        }
        else
        {
            tot++;//记录重复的字符串个数
        }
    }
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            string ss;
            cin>>ss;
            if(mp[ss]==0)
            {
                mp[ss]++;//记录新插入字符串出现的次数
            }
            else
            {
                tot++;//记录重复的字符串个数
            }
        }
        else
        {
            cout<<tot<<endl;//输出重复字符串个数下一轮重新累加
            tot=0;
        }
    }
    return 0;
}
