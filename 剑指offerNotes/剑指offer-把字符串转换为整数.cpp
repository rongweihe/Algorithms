/*
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
复制
+2147483647
    1a33
输出
复制
2147483647
    0
*/

//Author:https://github.com/rongweihe
//Date:2019/05/03
class Solution
{
public:
    int StrToInt(string str)
    {
        if((str[0]=='+'||str[0]=='-')&&(str[1]=='+'||str[1]=='-'))
            return 0;
        if (str == "")
            return 0;
        //小数点四舍五入的情况
        /*
        string s1=".";
        int pos=str.find(s1);
        if(pos>0)
            str=str.substr(0,pos);
        */
        long long  num=0;
        bool fg=1;
        //判断不合法的情况
        if (str.find_first_not_of("1234567890+-") < str.size())
            return 0;
        char ch = str[0];
        int i = 0;
        if (ch == '-')
        {
            fg = 0;
            i = 1;
        }
        else if (ch == '+')
        {
            fg = 1;
            i = 1;
        }
        else
        {
            i = 0;
        }
        while (i<str.size())
        {
            long long m = str[i]-48;
            num = num * 10 + m;
            // 判断是否溢出
            if( ((fg) && (num > 0x7FFFFFFF)) ||((!fg) && (num > 0x80000000)) )
            {
                num = 0;
                break;
            }
            i++;
        }
        if (!fg)
            num = -num;
        return num;
    }
};

剑指offer 的写法
class Solution
{
public:

    enum Status {kValid =0,kInvalid};
    int g_nStatus = kValid;
    int StrToInt(string str)
    {
        g_nStatus = kInvalid;
        long long num=0;
        const char* digit=str.c_str();
        if( digit!=NULL && *digit!='\0')
        {
            int minus=1;
            if(*digit=='-')
            {
                minus=-1;
                digit++;
            }
            else if(*digit=='+')
                digit++;
            while(*digit!='\0')
            {
                if(*digit>='0' &&*digit<='9')
                {
                    g_nStatus = kValid;
                    num=num*10+(*digit-'0');
                    digit++;
                    if( ((minus>0) && (num > 0x7FFFFFFF)) ||((minus<0) && (num > 0x80000000)) )
                    {
                        g_nStatus = kInvalid;
                        num = 0;
                        break;
                    }
                }
                else
                {
                    g_nStatus=kInvalid;
                    num=0;
                    break;
                }
            }
            if(g_nStatus==kValid)
                num*=minus;
        }
        return (int)num;
    }
};
