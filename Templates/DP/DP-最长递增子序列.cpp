#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
int n,m,T,a[maxn],dp[maxn];

//dp[i]表示以a[i]结尾的最长递增子序列长度
int dp_solve()
{
    memset(dp,0,sizeof(dp));
    int maxx = -1;
    for(int i=1; i<=n; ++i)
    {
        dp[i]=1;// 初始化为1，长度最短为自身
        for(int j=1; j<=i; ++j)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxx = max(maxx,dp[i]);
    }
    return maxx;
}
int bi_search(int len,int x)  //二分查找dp[]里面第一个大于等于x的数
{
    int left = 1, right = len, mid;
    while(left <= right)
    {
        mid = right + (left - right) / 2;
        if(x == dp[mid])
            return mid;
        else if(x > dp[mid])
            left = mid + 1;
        else if(x < dp[mid])
            right = mid - 1;
    }
    return left;
}
/*
O(NlogN)做法：贪心+二分
a[i]表示第i个数据。
dp[i]表示表示长度为i+1的LIS结尾元素的最小值。
利用贪心的思想，对于一个上升子序列，显然当前最后一个元素越小，越有利于添加新的元素，这样LIS长度自然更长。
因此，我们只需要维护dp数组，其表示的就是长度为i+1的LIS结尾元素的最小值，保证每一位都是最小值，这样子dp数组的长度就是LIS的长度。

dp数组具体维护过程同样举例讲解更为清晰。
假设存在一个序列d[1..9] = 2 1 5 3 6 4 8 9 7，可以看出来它的LIS长度为5。n
下面一步一步试着找出它。
我们定义一个序列B，然后令 i = 1 to 9 逐个考察这个序列。
此外，我们用一个变量Len来记录现在最长算到多少了

首先，把d[1]有序地放到B里，令B[1] = 2，就是说当只有1一个数字2的时候，长度为1的LIS的最小末尾是2。这时Len=1

然后，把d[2]有序地放到B里，令B[1] = 1，就是说长度为1的LIS的最小末尾是1，d[1]=2已经没用了，很容易理解吧。这时Len=1

接着，d[3] = 5，d[3]>B[1]，所以令B[1+1]=B[2]=d[3]=5，就是说长度为2的LIS的最小末尾是5，很容易理解吧。这时候B[1..2] = 1, 5，Len＝2

再来，d[4] = 3，它正好加在1,5之间，放在1的位置显然不合适，因为1小于3，长度为1的LIS最小末尾应该是1，这样很容易推知，长度为2的LIS最小末尾是3，于是可以把5淘汰掉，这时候B[1..2] = 1, 3，Len = 2

继续，d[5] = 6，它在3后面，因为B[2] = 3, 而6在3后面，于是很容易可以推知B[3] = 6, 这时B[1..3] = 1, 3, 6，还是很容易理解吧？ Len = 3 了噢。

第6个, d[6] = 4，你看它在3和6之间，于是我们就可以把6替换掉，得到B[3] = 4。B[1..3] = 1, 3, 4， Len继续等于3

第7个, d[7] = 8，它很大，比4大，嗯。于是B[4] = 8。Len变成4了

第8个, d[8] = 9，得到B[5] = 9，嗯。Len继续增大，到5了。

最后一个, d[9] = 7，它在B[3] = 4和B[4] = 8之间，所以我们知道，最新的B[4] =7，B[1..5] = 1, 3, 4, 7, 9，Len = 5。

于是我们知道了LIS的长度为5。

!!!!! 注意。这个1,3,4,7,9不是LIS，它只是存储的对应长度LIS的最小末尾。有了这个末尾，我们就可以一个一个地插入数据。虽然最后一个d[9] = 7更新进去对于这组数据没有什么意义，但是如果后面再出现两个数字 8 和 9，那么就可以把8更新到d[5], 9更新到d[6]，得出LIS的长度为6。

通过上述求解，可以发现dp数组是单调递增的，因此对于每一个a[i]，先判断是否可以直接插入到dp数组尾部，即比较其与dp数组的最大值即最后一位；如果不可以，则找出dp中第一个大于等于a[i]的位置，用a[i]替换之。
这个过程可以利用二分查找，因此查找时间复杂度为O(logN)，所以总的时间复杂度为O(NlogN)
*/
int bi_solve()
{
    int len=1;
    dp[1] = a[1];
    for(int i=2; i<=n; ++i)
    {
        if(a[i]>dp[len])
        {
            dp[++len] = a[i];
            //cout<<"a[i]="<<a[i]<<" "<<"len="<<len<<" "<<"dp[len="<<dp[len]<<endl;
        }
        else
        {
            int pos = bi_search(len,a[i]);
            //cout<<"pps=="<<pos<<"a[i]="<<a[i]<<endl;
            dp[pos] = a[i];
        }
    }
    return len;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
        }
        //int ans = dp_solve();
        int ans = bi_solve();
        cout<<ans<<endl;
    }
    return 0;
}
