/*
【1】考虑非法输入和输入0两种情况，对应的输出，atoi函数通过一个全局变量来区别这两种情况
如果是非法输入，则返回0并把全局变量标记；
如果是0则返回0不标记全局变量；
【2】考虑空字符串，只有一个+号或者-号
【3】考虑正整数溢出，负整数溢出情况
*/
enum Status{kVaild=0,kInVaild};
int g_InputVaild = kVaild;
class Solution33
{
public:
    int StrToInt(const char* str)
    {
        g_InputVaild = kInVaild;
        long long num = 0;
        if(str!=nullptr && *str!='\0')
        {
            bool minus = false;
            if(*str =='+')
                str++;
            else if(*str=='-')
            {
                str++;
                minus = true;
            }
            if(*str!='\0')
            {
                num = StrToIntCore(str,minus);
            }
        }
        return (int)num;
    }
    long long StrToIntCore(const char* digit, bool minus)
    {
        long long num = 0;
        while(*digit!='\0')
        {
            if(*digit>='0' && *digit<='9')
            {
                int flag = minus?-1:1;
                num = num*10 + flag*(*digit-'0');
                if( (minus&&num <(INT_MIN)) || (!minus&&num>(INT_MAX)) )
                   {
                       num = 0;
                       break;
                   }
                   digit++;
            }
            else
            {
                num=0;
                break;
            }
        }
        if(*digit=='\0')
        {
            g_InputVaild = kVaild;
        }
        return num;
    }
};
int main()
{
    Solution33 s;
    cout<<s.StrToInt("+234")<<endl;
    cout<<s.StrToInt("-234")<<endl;
    cout<<s.StrToInt("")<<endl;
    return 0;
}
