方法一：费马小定理
a^(p-1) ≡1 (mod p)

两边同除以a

a^(p-2) ≡1/a (mod p)

什么(,,• ₃ •,,)，这可是数论，还敢写1/a

应该写a^(p-2) ≡ inv(a) (mod p)

所以inv(a) = a^(p-2) (mod p)

这个用快速幂求一下，复杂度O(logn)(ง •̀_•́)ง 

LL pow_mod(LL a, LL b, LL p){//a的b次方求余p 
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}
LL Fermat(LL a, LL p){//费马求a关于p的逆元 
        return pow_mod(a, p-2, p);
}
 
方法二：扩展欧几里德算法
a*x + b*y = 1

如果ab互质，有解

 

这个解的x就是a关于b的逆元

y就是b关于a的逆元 两边同时求余b

 

a*x % b + b*y % b = 1 % b

a*x % b = 1 % b

a*x = 1 (mod b)

 

所以x是a关于b的逆元

反之可证明y

#include<iostream>
#include<cstdio>
using namespace std;
 
int n, b;
 
int ex_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int g = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
 
int main() {
    cin >> n >> b;
    for(int a = 1; a <= n; a++) {
        int x, y;
        int g = ex_gcd(a, b, x, y);
        int t = b / g;
        x = (x % t + t) % t;
        printf("%d",x);
    }
}
 

方法三：线性递推
当p是个质数的时候有
inv(a) = (p - p / a) * inv(p % a) % p

证明：
设x = p % a,y = p / a
于是有 x + y * a = p
(x + y * a) % p = 0
移项得 x % p = (-y) * a % p
x * inv(a) % p = (-y) % p
inv(a) = (p - y) * inv(x) % p
于是 inv(a) = (p - p / a) * inv(p % a) % p

然后一直递归到1为止，因为1的逆元就是1

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,mod;
ll inv[3000010];
int main()
{
    scanf("%lld %lld",&n,&mod);
    inv[1]=1;
    printf("1\n");
    for(int i=2;i<=n;i++)
    {
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        printf("%lld\n",inv[i]);
    }
    return 0;
}
