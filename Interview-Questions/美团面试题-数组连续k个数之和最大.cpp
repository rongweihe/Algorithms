#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+233;
//滑动窗口思路
int getContinusKnumMax(int a[],int n,int k)
{
    int maxSum = INT_MIN; // k个连续数之和
    int curSum = 0;       // 当前和
    for (int i = 0; i < n; ++i)
    {
        curSum += a[i];
        maxSum  = max(maxSum, curSum);
        if(i >= k - 1)
            curSum -= a[i - (k - 1)];
    }
    return maxSum;
}
int main()
{
    int a[]= {1,2,3,4,5,-6,8,11};
    int n = sizeof(a) / sizeof(int);
    cout<<get(a,n,3)<<endl; // 13
    return 0;
}
