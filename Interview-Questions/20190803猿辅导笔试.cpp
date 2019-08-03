//第一题
/*
 猿辅导第一题，带括号字符串解压缩
 3
A2B
(AA)2A
A2BC4D2
输出
AAB
AAAAA
AABCBCBCBCDD
*/
 #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+233;
const int MOD = 1e9+7;
int a[maxn];
int n,m,T;
string str;
string out(string str)
{
    int j=0;
    string ans = "";
    while(j<str.size())
    {
        string sub;
        //考虑有括号的情况
        if(str[j]=='(')
        {
            int l = ++j;
            int ok = 1;//只有ok==1判断第一次匹配的右括号，因为括号里面还可以包含括号
            while(str[j]!=')' || ok !=1)
            {
                if(str[j] == '(')
                {
                    ok++;
                }
                if(str[j]==')')
                {
                    ok--;
                }
                j++;
            }
            //考虑括号里面同样进行操作，递归处理
            sub = out(str.substr(l,j-l));
            ans+=sub;
            l = ++j;
            int zi = 0;
            while(str[j]>='0'&&str[j]<='9')
            {
                zi = zi*10 + str[j]-'0';
                j++;
            }
            for(int i=0; i<zi-1; ++i)
            {
                ans+=sub;
            }
        }
        else
        {
            //考虑只有大写字母的情况，直接统计数字，然后循环数字次，添加字符串
            string a = str.substr(j,1);
            ans+=a;
            int zi = 0;
            j++;
            while(str[j]>='0' && str[j]<='9')
            {
                zi = zi*10 + str[j]-'0';
                j++;
            }
            for(int i=0; i<zi-1; ++i)
            {
                ans+=a;
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        cin>>str;
        string tt = out(str);
        cout<<tt<<endl;
    }
    return 0;
}

 
// 第二题
/*
题目描述
学校联欢晚会的时候，为了使每一个同学都能参与进来，主持人常常会带着同学们玩击鼓传花的游戏。游戏规则是这样的：n个同学坐着围成一个圆圈，指定一个同学手里拿着一束花，主持人在旁边背对着大家开始击鼓，鼓声开始之后拿着花的同学开始传花，每个同学都可以把花传给自己左右的两个同学中的一个（左右任意），当主持人停止击鼓时，传花停止，此时，正拿着花没传出去的那个同学就要给大家表演一个节目。
聪明的小明提出一个有趣的问题：有多少种不同的方法可以使得从小明手里开始传的花，传了m次以后，又回到小明手里。对于传递的方法当且仅当这两种方法中，接到花的同学按接球顺序组成的序列是不同的，才视作两种传花的方法不同。比如有3个同学1号、2号、3号，并假设小明为1号，花传了3次回到小明手里的方式有1->2->3->1和1->3->2->1，共2种。
输入
输入共一行，有两个用空格隔开的整数n，m（3<=n<=30，1<=m<=30）
样例输入
3 3

输出
输出共一行，有一个整数，表示符合题意的方法数
样例输出
2
【笔试完思路】：
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+233;
const int MOD = 1e9+7;
int n,m,T;
int main()
{
   // freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(2, vector<int>(n));
    A[0][0] = 1;
    for (int i = 1; i < n; i++)
        A[0][i] = 0;
    int p = 1;
    for (int i = 1; i <= m; i++,p=1-p)
    {
        for (int j = 0; j < n; j++)
        {
            A[p][j] =(A[1 - p][(j - 1 + n) % n] *(1LL) %MOD) + (A[1 - p][(j + 1) % n] * (1LL)) %MOD;//DP的递推方程
            //A数组表示编号为0的人经过i次传递之后到达编号为j的人的方案数目。
        }
    }
    cout << A[1-p][0]%MOD << endl;
    return 0;
}
