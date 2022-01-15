/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();//这是左闭右开的的二分查找
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle; //此时目标在左区间，注意一直是左闭又开因此不用middle-1
            else if (nums[middle] < target)
                left = middle + 1; //此时目标在右区间
            else
                return middle;
        }
        return -1;

    }
};
/*class Solution {// 这是一个升序数组的二分查找
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle - 1; //此时目标在左区间
            else if (nums[middle] < target)
                left = middle + 1; //此时目标在右区间
            else
                return middle;
        }
        return -1;

    */
// @lc code=end

