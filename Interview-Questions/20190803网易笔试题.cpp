/*
大数 最大公约数
思路
gcd(a,b) = gcd(b , a \%b)gcd(a,b)=gcd(b,a%b)，
这是欧几里得算法。那我们只要实现a % b的计算。 a % b可以直接在输入的时候维护（详见代码）。
*/
//参考代码
#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long gcd(long long a,long long b)
{
    return a % b == 0 ?b : gcd(b , a % b) ;
}
int main()
{
    scanf("%s",s+1) ;
    long long a ; cin >> a;
    long long b = 0;
    for(int i = 1;s[i] != '\0';i++) {
        b = (b * 10 + s[i] - '0') % a;
    }
    cout << gcd(b , a) ;
    return 0;
}

//或者

/*
按位或

思路
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+233;
int a[maxn];
int q,len,op,x;
int main()
{
  //  freopen("in.txt","r",stdin);
    cin>>q;
    len = 0;
    for(int i=0; i<q; ++i)
    {
        cin>>op>>x;
        if(op==1)
        {
            a[len++]=x;
        }
        else
        {
            bool ok = false;
            int sum = 0;
            for(int i=0; i<len; ++i)
            {
                if((a[i]|x) == x )
                {
                    sum |= a[i];
                    if(sum==x )
                    {
                        //puts("YES");
                        ok =true;
                        break;
                    }
                }
                if(ok)
                    break;
            }
            if(ok)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
