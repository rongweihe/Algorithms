
#include<bits/stdc++.h>
using namespace std;
int getNum()
{
    int num;
    cout << "请输入一个数字：" << endl;
    // 从命令行输入这个浮点数
    cin >> num;
    // 清除输入流状态标志
    cin.clear();
    return num;
}
string convertNum(int num)
{
    static const string letter[] = {"零","一","二","三","四","五","六","七","八","九"};
    static const string unit[] = {"","S","B","Q","W","十","百","千","亿","十"};
    string src;
    string des;
    char tmp[12];
    sprintf(tmp, "%d", num);
    src.append(tmp);

    if ( num < 0 )
    {
        des.append("负");
        src.erase(0, 1);
    }

    int len = src.length();
    bool bPreZero = false;
    for ( int i = 0; i < len; i++)
    {
        int digit = src.at(i) - '0';
        int unit_index = len - i - 1;
        if (i == 0 && digit == 1 && (unit_index == 1 || unit_index == 5 || unit_index == 9))
        {
            des.append(unit[unit_index]);
        }
        else if ( digit == 0 )
        {
            bPreZero = true;
            if (unit_index ==  4 ||
                unit_index ==  8)
            {
                des.append(unit[unit_index]);
            }
        }
        else
        {
            if ( bPreZero )
            {
                des.append(letter[0]);
            }
            des.append(letter[digit]);
            des.append(unit[unit_index]);
            bPreZero = false;
        }
    }
    return des;
}
int main( int argc, char *argv[] )
{
    printf( "Hello World!\n" );

    char tmp[10];
    sprintf(tmp, "%d", 1);

    while ( 1)
    {
        int num = getNum();
        printf("NUM:%10d ==>> %s\n", num, convertNum(num).c_str());

    }
    return 0;
}
