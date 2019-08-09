//Create By @herongwei
//使用 C++ string 实现简单大整数相加模板
//注意传引用
string bigIntegerAdd(string& s1,string& s2)
{
    string a    = s1;
    string b    = s2;
    string res  = "";
    int len1    = a.length();
    int len2    = b.length();
    bool neg1    = false;
    bool neg2    = false;

    //进位
    int one_add = 0;
    int t1      = 0;
    int t2      = 0;

    //比较两个字符串，取较小一个的长度
    int min_len    = a.length()<b.length() ? a.length() : b.length();

    if(a[0]=='-')
        neg1 = true;
    if(b[0]=='-')
        neg2 = true;

    if(!neg1 && !neg2)
    {
        for(int i=1; i<=min_len; ++i)
        {
            one_add = (a[len1 - i] - '0' + b[len2 - i] - '0') + t1;
            //需要向前一位的数，如9+8=17，进一位:1
            t1      = (one_add / 10);
            t2      = (one_add % 10);
            //将每次保留的数存入结果字符串，注意顺序是反的，结果需倒置输出
            res.push_back(t2 + '0');
        }

        //将余下的直接添加到结果,注意前面可能前进一位
        int min_ = min_len;
        while(len1 > min_)
        {
            one_add = (a[len1 - 1 - min_] - '0' + t1);
            t1      = (one_add / 10);
            t2      = (one_add % 10);
            res.push_back(t2 + '0');
            ++min_;
        }
        while(len2> min_)
        {
            one_add = (b[len2 - 1 - min_] - '0' + t1);
            t1      = (one_add / 10);
            t2      = (one_add % 10);
            res.push_back(t2 + '0');
            ++min_;
        }
    }
    else if(neg1 || neg2)
    {
        //...
    }
    //将res反向输出
    reverse(res.begin(), res.end());
    return res;
}
