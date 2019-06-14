#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+233;

/*
*Date:2019/03/10
*github.com/rongweihe
*solution 1
*整数，且不考虑分数
*/
bool flag=false;
int aa[5];
bool judgePoint24(int now,int next,int ce) {
    if(ce ==3) {
       if ( (now+next==24)|| (now-next==24) || (now*next==24) || (next&&(now/next==24) )
            return true;
        return false;
    }
    if(judgePoint24(now+next,aa[ce+1],ce+1)) return true;
    if(judgePoint24(now,next+aa[ce+1],ce+1)) return true;

    if(judgePoint24(now-next,aa[ce+1],ce+1)) return true;
    if(judgePoint24(now,next-aa[ce+1],ce+1)) return true;

    if(judgePoint24(now*next,aa[ce+1],ce+1)) return true;
    if(judgePoint24(now,next*aa[ce+1],ce+1)) return true;

    if(next && now%next==0 && judgePoint24(now/next,aa[ce+1],ce+1)) return true;
    if(aa[ce+1] && next%aa[ce+1]==0 && judgePoint24(now,next/aa[ce+1],ce+1)) return true;
    return false;
}
/*
*github.com/rongweihe
*solution 2
*考虑分数
*/
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
private:
    bool valid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
        if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
        if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001)
            return true;
        return false;
    }
};

int main()
{
    aa[0]=1;
    aa[1]=3;
    aa[2]=4;
    aa[3]=6;
    sort(aa,aa+4);
    flag = false;
    do {
        if(judgePoint24(aa[0],aa[1],1)) {
            flag = true;
            puts("Yes");
            break;
        }
    }while(next_permutation(aa,aa+4));
    if(!flag)  puts("No");
    return 0;
}
