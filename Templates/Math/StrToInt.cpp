
/*StrToInt*/
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

const int maxn =1e5+233;
const long long inf =0x7fffffff;
const long long inff=0x80000000;
int n,m,k,t;
char str[maxn];
enum Status {kValid=0,kInvalid};
int g_nStatus = kValid;

long long StrToIntCore(const char* str,bool minus)
{
    long long num = 0;
    while(*str != '\0')
    {
        if(*str >='0' && *str<='9')
        {
            int flag = minus?-1:1;
            num = num*10+ flag*(*str - '0');
            if( (!minus && num >inf) || (minus && num < (signed int)inff))
            {
                num = 0;
                break;
            }
            str++;
        }
        else
        {
            num=0;
            break;
        }
    }
    if(*str == '\0')
    {
        g_nStatus = kValid;
    }
    return (int)num;
}

int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    if(str !=NULL && *str!= '\0')
    {
        bool minus=false;
        if(*str == '+') str++;
        else if(*str == '-')
        {
            str++;
            minus = true;
        }
        if(*str != '\0')
        {
            num = StrToIntCore(str,minus);
        }
    }
    return (int)num;
}
//
//    int ret=0;
//    stringstream s;
//    string tmpstr;
//    s<<str;
//    s>>tmpstr;
//    int len=tmpstr.length();
//    for(int i=0; i<len; ++i)
//    {
//        if(isdigit(tmpstr[i]))
//        {
//            ret = ret*10 + tmpstr[i]-'0';
//        }
//    }
//    return ret;

int main(int argc,char* argv[])
{
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        cout<<"str="<<str<<" "<<StrToInt(str)<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

/*Test*/
/*
in       out
5
123      123
23678    23648
00233300 2333
08888    8888
-56      -56
*/
