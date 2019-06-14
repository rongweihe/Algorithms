/*
Author: rongweihe
Date  : 2019/05/03
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
// 全排序，时间复杂度 O(nlogn)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty()||k>input.size()) return res;
         
        sort(input.begin(),input.end());
         
        for(int i=0;i<k;++i)
            res.push_back(input[i]);
         
        return res;
         
    }
};

//红黑树：multiset集合  利用greater<T>模板改变排序顺序 时间复杂度O（nlogk）
class Solution{
public:
    vector<int>GetLeastNumbers_Solution(vector<int>input,int k)
    {
        vector<int>res;
        int len = input.size();
        if(len<=0 || k>len) return res;
        //greater<T>模板，从大到小排序
        multiset<int,greater<int> >leastNums;
        vector<int>::iterator vec_it = input.begin();
        for(;vec_it!=input.end();++vec_it)
        {
            //将前k个元素插入集合
            if(leastNums.size()<k) leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                 multiset<int,greater<int> >::iterator greater_it =leastNums.begin();
                 if(*vec_it<*(leastNums.begin()))
                 {//如果后续元素<第一个元素，删除第一个，加入当前元素
                     leastNums.erase(greater_it);
                     leastNums.insert(*vec_it);
                 }
            }
        }
        res.assign(leastNums.begin(),leastNums.end());
        return res;
    }
};
