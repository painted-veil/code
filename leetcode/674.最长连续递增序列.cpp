/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {//时间复杂度O(n),空间复杂度O(n);
    if (nums.size() == 0) return 0;
    int result = 1;
    vector<int> dp(nums.size(),1);
    for (int i= 0; i < nums.size()-1; i++){
        if(nums[i+1]>nums[i]){
            dp[i+1] = dp[i] +1;
        }
        if(dp[i+1] >result) result = dp[i+1];
    }
    return result;

    }
};
// @lc code=end

