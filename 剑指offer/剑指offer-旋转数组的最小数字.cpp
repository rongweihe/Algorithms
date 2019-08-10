/*
Create By @herongwei 2019/08/10
【题目描述】
旋转数组的最小数字
【思路】
旋转之后的数组实际上可以划分成两个有序的子数组：前面子数组的大小都大于后面子数组中的元素
注意到实际上最小的元素就是两个子数组的分界线。本题目给出的数组一定程度上是排序的，因此我们试着用二分查找法寻找这个最小的元素。
（1）我们用两个指针 L,R 分别指向数组的第一个元素和最后一个元素。按照题目的旋转的规则，
第一个元素应该是大于最后一个元素的（没有重复的元素）。

但是如果不是旋转，第一个元素肯定小于最后一个元素。

（2）找到数组的中间元素。

中间元素大于第一个元素，则中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面。我们可以让第一个指针指向中间元素。

移动之后，第一个指针仍然位于前面的递增数组中。

中间元素小于第一个元素，则中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面。我们可以让第二个指针指向中间元素。

移动之后，第二个指针仍然位于后面的递增数组中。

这样可以缩小寻找的范围。
无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
*/
class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int sz = rotateArray.size();
        if(sz==0)
        {
            return 0;
        }
        int L = 0, R = sz - 1;
        int mid = 0;
        while(rotateArray[L] >= rotateArray[R])
        {
            if(R - L == 1)
            {
                mid = R;
                break;
            }
            mid = L + (R - L)/2;
            if(rotateArray[L]==rotateArray[R]&&rotateArray[L]==rotateArray[mid])
            {
                return minOrder(rotateArray,L,R);
            }
            if(rotateArray[mid] >= rotateArray[L])
            {
                L = mid;
            }
            else
            {
                R = mid;
            }
        }
        return rotateArray[mid];
    }
private:
// 顺序寻找最小值
    int minOrder(vector<int> &num,int L,int R)
    {
        int ret = num[L];
        for(int i = L + 1; i < R; ++i)
        {
            ret = min(ret,num[i]);
        }
        return ret;
    }
};
