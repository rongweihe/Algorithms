
## 题目描述
统计一个数字在排序数组中出现的次数。
总结七种解法。

【解法一 O(n)】

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int c=0;
        int len = data.size();
        if(len<=0) return 0;
        for(int i=0; i<len; ++i)
        {
            if(data[i]==k) c++;
        }
        return c;
    }
};
```



【解法二 利用 C++ STL count 函数 复杂度线性】

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return count(data.begin(),data.end(),k);
    }
};
```



【解法三 利用 C++ STL lower_bound，upper_bound 函数 O(log n)】

![img](https://img-blog.csdn.net/20180605171241611)

lower_bound：

功能：查找非递减序列[first,last) 内第一个大于或等于某个元素的位置。

返回值：如果找到返回找到元素的地址否则返回last的地址。

upper_bound:

功能：查找非递减序列[first,last) 内第一个大于某个元素的位置。

返回值：如果找到返回找到元素的地址否则返回last的地址。

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()<=0) return 0;
        int first = lower_bound(data.begin(),data.end(),k)-data.begin();
        int last  = upper_bound(data.begin(),data.end(),k)-data.begin();
        return last-first;
    }
};
```



【解法四 O(log n)】

equal_range 函数用于在序列中表示一个数值的第一次出现的位置与最后一次出现的位置。

```c++
// 利用C++STL 的二分查找
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto ans = equal_range(data.begin(), data.end(),k);
        return ans.second - resultPair.first;
    }
};
```



【解法五 递归二分查找 O(logn)】

```c++
//复杂度 O(logn)
class Solution
{
public:
    //如果数组中不包含数字K，返回-1否则返回第一个K在数组中的下标
    int GetFirstK(vector<int>&data,int len,int k,int start,int end)
    {
        if(start>end)
            return -1;
        int midIdx = (start+end)/2;
        int midVal = data[midIdx];

        //如果中间的数和K相等，判断这个数是不是第一个K
        if(midVal == k)
        {
            if(midIdx>0 && data[midIdx-1]!=k || midIdx==0)
                return midIdx;
            else
                end=midIdx-1;
        }
        //如果中间的数比K大，则K只有可能出现在前半段
        else if(midVal > k)
            end=midIdx-1;
        //如果中间的数比K小，则K只有可能出现在后半段
        else
            start = midIdx+1;
        //递归调用
        return GetFirstK(data,len,k,start,end);
    }
    //
    int GetLastK(vector<int>&data,int len,int k,int start,int end)
    {
        if(start>end)
            return -1;
        int midIdx = (start+end)/2;
        int midVal = data[midIdx];

        //如果中间的数和K相等，判断这个数是不是第一个K
        if(midVal == k)
        {
            if(midIdx<len-1 && data[midIdx+1]!=k || midIdx==len-1)
                return midIdx;
            else
                start=midIdx+1;
        }
        //如果中间的数比K小，则K只有可能出现在后半段
        else if(midVal < k)
            start=midIdx+1;
        //如果中间的数比K大，则K只有可能出现在前半段
        else
            end = midIdx-1;
        //递归调用
        return GetLastK(data,len,k,start,end);
    }
    int GetNumberOfK(vector<int> data,int k)
    {
        int ans=0;
        int len = data.size();
        if(len>0)
        {
            int first = GetFirstK(data,len,k,0,len-1);
            int last  = GetLastK(data,len,k,0,len-1);
            if(first>-1 && last>-1)
                ans=last-first+1;
        }
        return ans;
    }
};
```

【解法六 非递归二分查找 O(logn)】

```c++
//由于数组有序，所以使用二分查找方法定位k的第一次出现位置和最后一次出现位置
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int first = GetFirstK(data,k);
        int last = GetLastK(data,k);
        return last - first + 1;
    }
     
    //获取k第一次出现的下标
    int GetFirstK(vector<int> &data,int k){
        int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
        while(start <= end){
            if(data[mid] < k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return start;
    }
    //获取k最后一次出现的下标
    int GetLastK(vector<int> &data,int k){
         int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
        while(start <= end){
            if(data[mid] <= k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return end;
    }
};
```

【解法七 令人眼前一亮的解法 O(logn)】

```
因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
这两个数应该插入的位置，然后相减即可。
```

```c++
class Solution
{
public:
    int BinarySearch(vector<int> &data,double k){
        int start = 0,end = data.size()-1;
        while(start <= end){
            int mid = (end-start)/2+start;
            if(data[mid] < k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return start;
    }
    int GetNumberOfK(vector<int> data,int k)
    {
       return BinarySearch(data,k+0.5) - BinarySearch(data,k-0.5);
    }
};
```

