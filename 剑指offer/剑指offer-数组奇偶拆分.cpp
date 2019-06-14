/*
Author: github.com/rongweihe
Date  : 2019-04-13
题目  : 数组奇偶拆分
input : 1,2,3,4,5,6,7,8
output: 1,3,5,7,2,4,6,8
思路：新建一个数组先把原数组中的奇数push进去再把偶数push进去，然后用新数组数据覆盖原数组即可
时间复杂度O(n),空间复杂度O(n)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int len = array.size();
        if(len ==0 || len ==1)
            return;

        vector<int> res;
        for(int i = 0; i < len; ++i)
        {
            if(array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for(int i = 0; i < len; ++i)
        {
            if(array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        array = res;
    }
};
int main()
{
    //freopen("in.txt","r",stdin);
    Solution ret;
    vector<int>array;
    int a[]= {1,2,3,4,5,6,7,8};
    for(int i=0; i<sizeof(a)/sizeof(int); ++i)
        array.push_back(a[i]);
    ret.reOrderArray(array);
    for(int i=0; i<array.size(); ++i)
        cout<<"array[i]="<<array[i]<<endl;
    return 0;
}


