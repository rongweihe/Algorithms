/*
Create By@ herongwei 2019/08/17
LeetCode 394 字符串解码
3[a]2[bc] return "aaabcbc".
*/
#include <bits/stdc++.h>
using namespace std;

string decodeString(string &s)
{
    string ans="";
    int num=0;
    int len = s.size();
    if(len<0)
        return ans;
    std::stack<int> num_stack;
    std::stack<string> str_stack;
    for(int i=0; i<len; ++i)
    {
        //遇到数字转换
        if(s[i]>='0'&&s[i]<='9')
        {
            num=num*10+s[i]-'0';
        }
        //遇到左括号压入数字和字符串，同时记得清空，准备后面括号的遍历
        //这里一定是先压栈在清空
        else if(s[i]=='[')
        {
            num_stack.push(num);
            cout<<"ans[[="<<ans<<endl;
            str_stack.push(ans);
            num=0,ans.clear();
        }
        //遇到右括号开始计算，取出数字栈顶，循环增加字符串的长度，并且将得到的字符串记录，同时清空字符串栈
        else if(s[i]==']')
        {
            int k = num_stack.top();
            num_stack.pop();
            for(int j=0; j<k; ++j)
                str_stack.top()+=ans;
            ans=str_stack.top(),str_stack.pop();
        }
        else
        {
            ans+=s[i];
        }
    }
    return ans;
    cout<<"ans="<<ans<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    string str="";
    cin>>str;
    string result = "";
    result = decodeString(str);
    cout<<result;
    return 0;
}

/*
Create By@ herongwei 2019/08/17
字符串解码 加强版
HG[3|B[2|CA]]F  return HGBCACABCACABCACAF
*/
#include <bits/stdc++.h>
using namespace std;

string decodeString(string &s)
{
    string ans="";
    int num=0;
    int len = s.size();
    if(len<0)
        return ans;
    std::stack<int> num_stack;
    std::stack<string> str_stack;
    for(int i=0; i<len; ++i)
    {
        //遇到数字转换
        if(s[i]>='0'&&s[i]<='9')
        {
            num=num*10+s[i]-'0';
        }
        else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans+=s[i];
        }
        //将'|'前的数字压入nums栈内， 字母字符串压入strs栈内
        else if(s[i]=='|')
        {
            num_stack.push(num);
            num=0;
        }
        else if(s[i]=='[')
        {
            str_stack.push(ans);
            ans.clear();
        }
        //遇到右括号开始计算，取出数字栈顶，循环增加字符串的长度，并且将得到的字符串记录，同时清空字符串栈
        else if(s[i]==']')
        {
            int k = num_stack.top();
            num_stack.pop();
            for(int j=0; j<k; ++j)
                str_stack.top()+=ans;
            ans=str_stack.top(),str_stack.pop();
        }
    }
    return ans;
    cout<<"ans="<<ans<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    string str="";
    cin>>str;
    string result = "";
    result = decodeString(str);
    cout<<result;
    return 0;
}
