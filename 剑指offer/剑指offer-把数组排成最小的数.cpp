/*
Author: https://github.com/rongweihe
Date  : 2019/04/30
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
【思路】
对 vector 容器内的数据进行排序，按照将a 和 b 转为 string 后，若 a＋b<b+a，则a排在前的规则排序,
如 3 32 因为 323 < 332 所以 排序后为 32 3 
to_string() 可以将 int 转化为 string
*/
class Solution
{
public:
    static  bool cmp(int a,int b)
    {
        string s1 = to_string(a)+to_string(b);
        string s2 = to_string(b)+to_string(a);
        return s1<s2;
    }
    string PrintMinNumber(vector<int> &numbers)
    {
        string ans = "";
        int size = numbers.size();
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0; i<size; ++i)
        {
            ans+=to_string(numbers[i]);
        }
        return ans;
    }
};
