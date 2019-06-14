/*
author: rongweihe
https://github.com/rongweihe/ACM-ICPC/new/master/Classic-Problem/ReversePairs.cpp
大概思路是归并排序的思想，先分为2个左右部分，
左部分的逆序对(只在左部分取2个数)，右部分的逆序对(只在右部分取2个数)，
满足在左部分取一个数，右部分取一个数的逆序对，
以上全部加起来就是总的逆序对。计算左右部分的逆序对的时候，利用递归。
*/
class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        return merge(data, 0, data.size() - 1);
    }
    //计算满足左部分一个数，右部分一个数条件的逆序对,此时左右部分已排好序
    int merge_count(vector<int> &data, int L, int mid, int R)
    {
        vector<int> tmp(data);
        int count = 0;
        int i = L;
        int j = mid + 1;
        int k = L;
        while ( i <= mid && j <= R)
        {
            if (data[i] <=data[j])
                tmp[k++] = data[i++];
            else
            {
                tmp[k++] = data[j++];
                count += mid - i+1;
            }
        }
        while (i <= mid)
            tmp[k++] = data[i++];
        while (j <= end)
            tmp[k++] = data[j++];
        for (int m = L; m <= R; m++)
            data[m] = tmp[m];
        return count;
    }
    int merge(vector<int> &data, int L, int R)//左右部分分别递归，
    {
        if (L >= R)
            return 0;
        int mid = (L + R) / 2;
        int left=merge(data, L, mid);
        int right=merge(data, mid + 1, R);
        int count = merge_count(data, L, mid, R);
        return left + right + count;
    }
};
