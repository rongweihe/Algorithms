
/*
*file  :将阿拉伯数字转换中文大写汉字
*Author: herongwei
*Date  : 2019/07/18
*/
class changeNum {
public:
    int numOfLen(int num) {
        int len = 0;
        if(num == 0)
            return 1;
        while(num > 0) {
            num /= 10;
            len++;
        }
        return len;
    }
    //从后往前构造中文汉字，个十百千万
    string change(int num) {
        string str = "";
        int tmp = 0;
        int k = num;
        int len = numOfLen(k);
        for(int i = 0; i < len; ++i) {
            tmp = k%10;
            switch(tmp) {
            case 0:
                str = "零"+str;
                break;
            case 1:
                str = "壹"+str;
                break;
            case 2:
                str = "贰"+str;
                break;
            case 3:
                str = "叁"+str;
                break;
            case 4:
                str = "肆"+str;
                break;
            case 5:
                str = "伍"+str;
                break;
            case 6:
                str = "陆"+str;
                break;
            case 7:
                str = "柒"+str;
                break;
            case 8:
                str = "捌"+str;
                break;
            case 9:
                str = "玖"+str;
                break;
            }
            if(i == 0 && i < len - 1)
                str = "拾" + str;
            else if(i == 1 && i < len - 1)
                str = "佰" + str;
            else if(i == 2 && i < len - 1)
                str = "仟" + str;
            k /= 10;
        }
        return str;
    }
    //再将每个数字组合并为万亿兆的形式
    string getAnsNum(long long num) {
        string str = "";
        for(int i = 0; num != 0; ++ i) {
            int tmp = num%10000;
            num /= 10000;
            str=change(tmp)+str;
            if(i == 0 && num != 0)
                str = "万" + str;
            else if(i == 1 && num != 0)
                str = "亿" + str;
            else if(i == 2 && num != 0)
                str = "兆" + str;
        }
        return str;
    }
};
int main() {
    //freopen("in.txt","r",stdin);
    long long int num=0;
    changeNum s;
    while(cin>>num) {
        cout<<s.getAnsNum(num)<<endl;
    }
    return 0;
}
/*
input
1
2
3
4
5
12
345
1234
23456
789034
8909845
output
壹
贰
叁
肆
伍
壹拾贰
叁佰肆拾伍
壹仟贰佰叁拾肆
贰万叁仟肆佰伍拾陆
柒拾捌万玖仟零佰叁拾肆
捌佰玖拾零万玖仟捌佰肆拾伍
*/
