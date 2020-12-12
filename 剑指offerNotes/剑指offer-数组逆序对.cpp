/*
Author: github.com/rongweihe
Date  : 2019/05/01
Solution:
统计逆序对的过程，先把数组分隔成子数组，先统计出子数组内部的逆序对数目，然后再统计出
相邻子数组之间的逆序对数目，在统计逆序对的过程中，还需要对数组进行排序，这里使用归并
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int MOD = (1e9+7);
    int InversePairs(vector<int> data)
    {
        int cnt = 0;
        if (data.size()>0)
            mergeS(data, 0, data.size() - 1,cnt);
        return cnt;
    }
    void mergeS(vector<int>&a,int L,int R,int &cnt)
    {
        if(L>=R) return ;//递归的终止条件
        int M = L+(R-L)/2;//计算中间值，注意溢出
        mergeS(a,L,M,cnt);//递归分
        mergeS(a,M+1,R,cnt);
        mergeC(a,L,M,R,cnt);//治
    }
     /*
     * 将一个数组中的两个相邻有序区间合并成一个
     */
    void mergeC(vector<int>&a,int L,int M,int R,int &cnt)
    {
        int *c = new int[R-L+1];
        //vector<int>c(R-L+1,0);
        int i=L,j=M+1,k=0;
        //下面就开始两两进行比较，若前面的数大于后面的数，就构成逆序对
        while(i<=M && j<=R)
        {
        //若前面小于后面，直接存进去，并且移动前面数所在的数组的指针即可
            if(a[i]<=a[j])
                c[k++]=a[i++];
            else
            {
                c[k++]=a[j++];
                cnt+=M-i+1;// core code, calculate InversePairs............
                cnt%=MOD;
            }
        }
        //判断哪个子数组中还有剩余的数据
        while(i<=M)
            c[k++]=a[i++];
        while(j<=R)
            c[k++]=a[j++];
        //将c数组数据拷贝回a[p..r]
        for(int p=0; p<k; ++p)
            a[L+p]=c[p];
        delete c;
    }
};
