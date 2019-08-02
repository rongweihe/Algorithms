/*
【题目描述】：
给定数组a, 里面的元素先严格递增后严格递减, 求最大值元素的下标.
【思路】：二粉查找 时间复杂度 nlog(n)
*/
int findPeak(int nums[],int len) {
    if (len > 0) {
        if (len == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) { //数组单调递减
            return 0;
        }
        int index = len - 1;
        if (nums[index] > nums[index-1]) { //数组单调递增
            return index;
        }
        int i = 0, j = index;
        int mid = 0;
        while (i < j) { //二分查找
            mid = (i + j) / 2;
            //处于顶峰
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid + 1]) { //处于下坡段, 即递减段
                j = mid - 1;
            }
            else if (nums[mid] > nums[mid - 1]) { //处于上坡段, 即递增段
                i = mid + 1;
            }
        }
    }
    return -1;
}
