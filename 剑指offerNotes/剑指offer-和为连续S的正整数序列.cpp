题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,
他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

//方法一 滑动窗口
class Solution
{
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        int L=1,R=2;
        vector<vector<int> >allRes;
        while(L<R)
        {
            //由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
            int curSum = (L + R) * (R - L + 1) / 2;
            if(curSum==sum)
            {
                vector<int> res;
                for(int i=L; i<=R; ++i)
                    res.push_back(i);
                allRes.push_back(res);
                L++;
            }

            // 两个窗口都是从左边出发，不是两边夹逼。另外，当小于目标数时high++；大于目标数时low++，
            // 如果是high--，窗口无法移动，整个结果在第一次大于目标数之后就不会往后移动，
            // 相反，而是在在这个low和high之间夹逼试探，最终啥都找不到或者只能找到一个。
            //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
            if(curSum < sum)
            {
                R++;
            }
            //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
            if(curSum > sum)
            {
                L++;
            }
        }
        return allRes;
    }
};

方法二
/*
参考 链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe

1）由于我们要找的是和为S的连续正数序列，因此这个序列是个公差为1的等差数列，而这个序列的中间值代表了平均值的大小。假设序列长度为n，那么这个序列的中间值可以通过（S / n）得到，知道序列的中间值和长度，也就不难求出这段序列了。
2）满足条件的n分两种情况：
n为奇数时，序列中间的数正好是序列的平均值，所以条件为：(n & 1) == 1 && sum % n == 0；
n为偶数时，序列中间两个数的平均值是序列的平均值，而这个平均值的小数部分为0.5，所以条件为：(sum % n) * 2 == n.
3）由题可知n >= 2，那么n的最大值是多少呢？我们完全可以将n从2到S全部遍历一次，但是大部分遍历是不必要的。为了让n尽可能大，我们让序列从1开始，
根据等差数列的求和公式：S = (1 + n) * n / 2，得到.

最后举一个例子，假设输入sum = 100，我们只需遍历n = 13~2的情况（按题意应从大到小遍历），n = 8时，得到序列[9, 10, 11, 12, 13, 14, 15, 16]；n  = 5时，得到序列[18, 19, 20, 21, 22]。
完整代码：时间复杂度为 O(sqrt(n))

import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int n = (int) Math.sqrt(2 * sum); n >= 2; n--) {
            if ((n & 1) == 1 && sum % n == 0 || (sum % n) * 2 == n) {
                ArrayList<Integer> list = new ArrayList<>();
                for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++) {
                    list.add(k);
                }
                ans.add(list);
            }
        }
        return ans;
    }
}
*/
