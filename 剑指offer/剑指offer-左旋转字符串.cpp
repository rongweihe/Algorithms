/*
三种方法
*/




//方法一：三次翻转，	以"abcdefg"为例,我们可以把它分为两部分。由于想把它的前两个字符移到后面,我们就把前两个字符分到第一部分,把后面的所有字符都分到第二部分。
//我们先分别翻转这两部分,于是就得到"bagfedc"。接下来我们再翻转整个字符串,得到的"cdefgab"刚好就是把原始字符串左旋转2位的结果。
class Solution
{
public:
    void Reverse(string &str,int L,int R)
    {
        int i=L,j=R;
        while(i<j)
        {
            swap(str[i++],str[j--]);
        }
    }
    string LeftRotateString(string str, int n)
    {
        if(str.size())
        {
            int len = str.size();
            if(len>0&&n>0&&n<len)
            {
                int leftBegin  = 0;
                int leftEnd    = n-1;
                int rightBegin = n;
                int rightEnd   = len-1;
                Reverse(str,leftBegin,leftEnd);
                Reverse(str,rightBegin,rightEnd);
                Reverse(str,leftBegin,rightEnd);
            }
        }
        return str;
    }
};
//方法二：跟方法一差不多，调用库函数 reverse
class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};
//方法三: 代码精简，在原先字符串基础上再拷贝一份，然后截取子串
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }
};
