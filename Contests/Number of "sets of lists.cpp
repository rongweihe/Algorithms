/*
Number of "sets of lists": number of partitions of {1,...,n} into any number of lists, where a list means an ordered subset. 
(Formerly M2950 N1190)

%I M2950 N1190

%S 1,1,3,13,73,501,4051,37633,394353,4596553,58941091,824073141,

%T 12470162233,202976401213,3535017524403,65573803186921,

%U 1290434218669921,26846616451246353,588633468315403843,13564373693588558173,327697927886085654441,8281153039765859726341

%N Number of "sets of lists": number of partitions of {1,...,n} into any number of lists, where a list means an ordered subset.

%C Determinant of n X n matrix M=[m(i,j)] where m(i,i)=i, m(i,j)=1 if i > j, m(i,j)=i-j if j > i. - _Vladeta Jovovic_, Jan 19 2003
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
unsigned long long b[]={1,3,13, 73, 501, 4051, 37633, 394353, 4596553, 58941091, 824073141, 12470162233, 202976401213, 3535017524403, 65573803186921, 1290434218669921, 26846616451246353, 588633468315403843, 13564373693588558173};
unsigned long long a[maxn];
unsigned long long  func(int x)
{
    a[0]=a[1]=1;
    for(long long i=2; i<=19; ++i)
        a[i] = (2*i-1)*a[i-1] -(i-1)*(i-2)*a[i-2];
    return a[x];
}
int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        cout<<func(n)<<endl;
        cout<<b[n-1]<<endl;
    }
    return 0;
}
