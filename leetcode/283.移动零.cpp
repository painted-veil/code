/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                nums[j++] = nums[i];//不等于0的全部移到左边
            }

        }
        while(j<n){
            nums[j++] = 0;//剩下的全是等于0的
        }
    }
};
// @lc code=end

