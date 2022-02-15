/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums,int target,bool lower){//时间复杂度O(logn),空间复杂度O(1)
        int left = 0;
        int right = nums.size() -1;
        int ans = nums.size();
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)){
                right = mid -1;
                ans = mid;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums,target,true);
        int rightIndex = binarySearch(nums,target,false) -1;
        if(leftIndex<=rightIndex && rightIndex <nums.size()&& nums[leftIndex] == target&& nums[rightIndex] ==target){
            return vector<int>{leftIndex,rightIndex};
        }
        return vector<int>{-1,-1};
    }
};
// @lc code=end

