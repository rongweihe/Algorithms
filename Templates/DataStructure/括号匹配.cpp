/* 
Author: https://github.com/rongweihe/ACM-ICPC/new/master/Classic-Problem/括号匹配.cpp
Date:   2019/04/09
Problem:
Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
Accepted

Solution:
判断是否满足匹配关系，使用栈遍历一遍即可。
当判断是 s[i]=='(' || s[i]=='{' || s[i]=='[' 就压栈；当判断 sta.size()>0 且满足输入的字符的匹配字符正好也是栈顶元素，则弹出栈，
最后判断栈是否为空即可。
*/


#include <bits/stdc++.h>
using namespace std;
std::string str;
bool isStrMatch(string &s){
    int len = s.size();
    std::stack<char>sta;
    for(int i=0; i<len; ++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') sta.push(s[i]);
        else if(sta.size()>0 && ( (s[i]==')' && sta.top()=='(') || (s[i]=='}' && sta.top()=='{') || (s[i]==']' && sta.top()=='[')))
            sta.pop();
        else return false;
    }
    return sta.size() == 0;
}
int main(){
    freopen("in.txt","r",stdin);
    while(cin>>str){
        cout<<isStrMatch(str)<<endl;
    }
    return 0;
}

/*
Sample input
[({})]
()[]{}
([)]
Sample output
1
1
0
*/
