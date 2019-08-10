/*
Create By @herongwei 2019/08/10
【题目描述】
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
【思路】
先遍历一次字符串,这样就能统计出字符串中空格的总数,并可以由此计算出替换之后的字符串的总长度。
每替换一个空格,长度增加2,因此替换以后字符串的长度等于原来的长度加上2乘以空格数目。
还是以前面的字符串"We are happy."为例。"We are happy."这个字符串的长度是14 (包括结尾符号"0'),
里面有两个空格,因此替换之后字符串的长度是18.从字符串的后面开始复制和替换。
首先准备两个指针: P1,和P2.P1指向原始字符串的末尾,而P2指向替换之后的字符串的末尾,
接下来我们向前移动指针P1,逐个把它指向的字符复制到P2指向的位置,直到碰到第一个空格为止。
*/
class Solution
{
public:
    void replaceSpace(char *str,int length)
    {
        if(str==nullptr || length<0)
            return;
        int old_len = strlen(str);
        int blank_sum  = 0;
        for(int i=0; i<old_len; ++i)
        {
            if(str[i]==' ')
                blank_sum++;
        }
        int new_len = old_len+blank_sum*2;
        if(new_len>length)
            return;

        int p_old_len = old_len;
        int p_new_len = new_len;

        while(p_old_len>=0 && p_old_len<p_new_len)
        {
            if(str[p_old_len]==' ')
            {
                str[p_new_len--]='0';
                str[p_new_len--]='2';
                str[p_new_len--]='%';
            }
            else
            {
                str[p_new_len--] = str[p_old_len];
            }
            --p_old_len;
        }
    }
};
