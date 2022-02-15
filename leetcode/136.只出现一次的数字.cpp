/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        if(nums.size() > 1){
            for(int i = 1; i < nums.size(); i++){
                ans = ans ^ nums[i];//异或，相同数字异或后结果则0，0与不同数字异或仍为该数字
            }
        }
        return ans;
    }
};
// @lc code=end

