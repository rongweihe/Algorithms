> Author: rongweihe
> Date  : 2019/05/03

> 题目描述
> 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
> 输入描述:
> 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

思路：
参考：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7

> 思路：递归法，问题转换为先固定第一个字符，求剩余字符的排列；求剩余字符排列时跟原问题一样。
> (1) 遍历出所有可能出现在第一个位置的字符（即：依次将第一个字符同后面所有字符交换）；
> (2) 固定第一个字符，求后面字符的排列（即：在第1步的遍历过程中，插入递归进行实现）。
> 需要注意的几点：
> (1) 先确定递归结束的条件，例如本题中可设begin == str.size() - 1; 
> (2) 形如 aba 或 aa 等特殊测试用例的情况，vector在进行push_back时是不考虑重复情况的，需要自行控制；
> (3) 输出的排列可能不是按字典顺序排列的，可能导致无法完全通过测试用例，考虑输出前排序，或者递归之后取消复位操作。

![tup](https://uploadfiles.nowcoder.com/images/20170705/7578108_1499250116235_8F032F665EBB2978C26C4051D5B89E90)

```c++
class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string>res;
        if(str.size()<=0) return res;
        Permutation(res,str,0);
        sort(res.begin(),res.end());
        return res;
    }
    //遍历第begin位的所有可能性
    void Permutation(vector<string>&res,string &str,int begin)
    {
        //递归条件出口
        if(begin == str.size()-1) res.push_back(str);
        //交换后面的字符
        for(int i=begin; i<=str.size()-1; ++i)
        {
            if(i!=begin && str[i]==str[begin]) continue;
            swap(str[i],str[begin]);
            Permutation(res,str,begin+1);
            swap(str[i],str[begin]);
        }
    }
};
```
