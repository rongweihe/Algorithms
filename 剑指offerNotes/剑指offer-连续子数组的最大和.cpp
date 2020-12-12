/*
Author: github.com/rongweihe
Date  : 2019-04-13
题目  : 连续子数组的最大和
input : 6,-3,-2,7,-15,1,2,2
output: 8
思路：
dp[i] 表示以元素 array[i] 结尾的最大连续子数组和.
以[-2,-3,4,-1,-2,1,5,-3]为例
可以发现,
dp[0] = -2
dp[1] = -3
dp[2] = 4
dp[3] = 3
以此类推,会发现
dp[i] = max{dp[i-1]+array[i],array[i]}
时间复杂度O(n),空间复杂度O(1)


 
#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    int curSum = 0;
    int maxSum = 0x80000000;
    int n      = array.size();
    for(int i=0; i<n; ++i){
        curSum = max(curSum + array[i], array[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
    }
};
int main()
{
    //freopen("in.txt","r",stdin);
    Solution ret;
    vector<int>array;
    int a[]={6,-3,-2,7,-15,1,2,2};
    for(int i=0; i<sizeof(a)/sizeof(int); ++i) array.push_back(a[i]);
    printf("%d\n",ret.FindGreatestSumOfSubArray(array)); // 8
    return 0;
}

/*
连续子数组的最大和
使用动态规划
F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
F（i）=max（F（i-1）+array[i] ， array[i]）
res：所有子数组的和的最大值
res=max（res，F（i））
*/
int FindGreatestSumOfSubArray(int array[],int n)
{
    int ret= array[0]; //记录当前所有子数组的和的最大值
    int maxSum=array[0];   //包含array[i]的连续数组最大值
    for (int i=1; i < n; ++i)
    {
        maxSum =max(maxSum+array[i], array[i]);
        ret    =max(maxSum, ret);
    }
    return ret;
}
*/
