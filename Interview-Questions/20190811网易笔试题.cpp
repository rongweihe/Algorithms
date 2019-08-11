//题意：有k次随意修改任意字符的机会，让我们找出最长的重复字符的字符串长度
//两种方法：滑动窗口和暴力法
int deal(string s, int k)
{
    int res = 0, maxSum = 0, start = 0;//maxSum字符出现次数最多数
    vector<int> counts(26, 0);
    for(int i=0; i<s.size(); i++)
    {
        maxSum = max(maxSum, ++counts[s[i]-'A']);
        cout<<"maxSum="<<maxSum<<endl;
        while ((i-start+1)-maxSum>k)//滑动窗口内判断条件
        {
            cout<<"i="<<i<<"start="<<start<<endl;
            counts[s[start]-'A'] -=1;
            start +=1;
        }
        cout<<"i-start+1="<<i-start+1<<endl;
        res = max(res, i-start+1);  // i-start+1的最大子字符串长度。
    }
    return res;
}

int deal2(string &s,int k)
{
   //分别记录
   // cur：当前字符前面已经匹配的连续最长N字符长度
   // pre：
   // preSum：
   // used：修改的次数
    int preSum=0,pre=0,cur=0,used=0;
    int maxLen = INT_MIN;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='N')
        {
            cur++;
            cout<<"cur=="<<cur<<endl;
        }
        else
        {
            if(used < k) used++;
            preSum = pre;
            pre=cur;
            cur=0;
            cout<<"used=="<<used<<endl;
            cout<<"pre=="<<pre<<endl;
            cout<<"preSum=="<<preSum<<endl;
            cout<<"cur=="<<cur<<endl;
        }
        maxLen = max(preSum+pre+cur+used,maxLen);
        cout<<"maxLen="<<maxLen<<endl;
    }
    return maxLen;
}
