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

/*
求 长度为K的连续子序列的最大值的最小值
参考链接：https://www.nowcoder.com/discuss/216237?type=0&order=0&pos=5&page=1

最大最小值
思路
首先注意到答案按顺序不减。
考虑把数字从大到小插入，当前插入数字u，那么假设某个k满足ans[k] <= u，则u和u之前的数字把序列分成了一段段，k要满足k <= 这些段中最长的。这样处理完毕之后再填入处理过程中没有填的位置。

参考代码
*/
#include<bits/stdc++.h>
using namespace std;
multiset<int> st ;
int n , k;
struct num
{
    int v ;
    int id;
}h[100005];
bool cmp(num a,num b)
{
    return a.v < b.v;
}
int L[100005] , R[100005];
int ans[100005];
int main()
{
    scanf("%d",&n) ;
    for(int i = 1;i <= n;i++) {
        scanf("%d",&h[i].v) ;
        h[i].id = i;
    }
    sort(h + 1 , h + n + 1, cmp) ;
    for(int i = 1;i <= n;i++) {
        L[i] = i - 1,R[i] = i + 1; ans[i] = 2e9;
    }
    for(int i = 1;i <= n;i++) {
        int a = h[i].id - L[h[i].id] - 1 , b = R[h[i].id] - h[i].id - 1 ;
        if(a) st.erase(st.find(a));
        if(b) st.erase(st.find(b)) ;
        st.insert(a + b + 1) ;
        L[R[h[i].id]] = L[h[i].id] ; R[L[h[i].id]] = R[h[i].id] ;
        multiset<int>::iterator it = st.end() ; it--;
        ans[*it] = min(ans[*it] , h[i].v) ;
    }
    for(int i = n ; i >= 1;i--){
        if(ans[i] == (2e9)) ans[i] = ans[i + 1];
    }
    for(int i = 1;i <= n;i++) printf("%d ",ans[i]) ;
    return 0;
}
