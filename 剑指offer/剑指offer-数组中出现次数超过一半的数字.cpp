/*
Author: rongweihe
Date  : 2019/05/03
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
思路：《剑指offer》
从另外一个角度来解决这个问题。数组中有一个数字出现的次数超过数组长度的一半,也就是说它出现的次数比其他所有数字出现次数的和还要多。
因此我们可以考虑在遍历数组的时候保存两个值:一个是数组中的一个数字,一个是次数。
当我们遍历到下一个数字的时候,如果下一个数字和我们之前保存的数字相同,则次数加1；
如果下一个数字和我们之前保存的数字不同,则次数减1。如果次数为零；
我们需要保存下一个数字,并把次数设为1,由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多,那么要找的数字肯定是最后一次把次数设为1时对应的数字。
*/
class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int n=numbers.size();
        if(n<=0) return 0;
        int ret = numbers[0],c=1;
        for(int i=1; i<n; ++i)
        {
            if(numbers[i]==ret) c++;
            else c--;
            if(c==0)
            {
                ret=numbers[i];
                c=1;
            }
        }
        //check 是否合法
        c=0;
        for(int i=0; i<n; ++i) if(numbers[i]==ret) c++;
        if(c*2>n) return ret;
        else return 0;
    }
};
