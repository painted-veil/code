/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {//二分法，时间复杂度O(logn)
        int left = 0;
        int right = nums.size() -1;
        while(left < right) {
            if((right - left) == 1)//Left和right相邻时，最小值只存在于left right区间
                break;
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left] && nums[mid] > nums[right]){
                left = mid;
            }else if(nums[left] > nums[mid] && nums[mid] < nums[right]){
                right = mid;
            }else if (nums[left] <nums[mid] && nums[mid] < nums[right]){
                break;
            }
        }
        return min(nums[left],nums[right]);
    }
};
// @lc code=end

