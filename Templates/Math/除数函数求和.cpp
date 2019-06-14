题目：https://loj.ac/problem/124
//参考代码
//github.com/rongweihe
// 除数函数求和
/*
线性筛,把所有的ik筛出来。就是质数直接算，
其他的根据在被筛掉的时候递推出来。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1e7 + 10;
int n, k, i, j, tot, f[N], primes[N / 10];
bool isPrime[N];
template <typename T>
inline T read(T& x) {
    x = 0;
    int f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x = f ? -x : x;
}
int quickPow(int a, int n) {
    if (a == 0)
        return 0;
    int res = 1;
    while (n) {
        if (n & 1)
            res = (ll)res * a % MOD;
        a = (ll)a * a % MOD;
        n >>= 1;
    }
    return res;
}
inline void up(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int solve(int n, int k) {
    int ans = 0;
    for (f[1] = isPrime[1] = i = 1; i <= n; ++i) {
        if (!isPrime[i])
            primes[++tot] = i, f[i] = quickPow(i, k);
        for (j = 1; j <= tot && (ll)i * primes[j] <= n; ++j) {
            isPrime[i * primes[j]] = 1;
            f[i * primes[j]] = (ll)f[i] * f[primes[j]] % MOD;
            if (i % primes[j] == 0)
                break;
        }
        up(ans, (ll)f[i] * (n / i) % MOD);
    }
    return ans;
}
int main() {
    //freopen("in.txt","r",stdin);
    read(n), read(k);
    printf("%d\n", solve(n, k));
    return 0;
}
