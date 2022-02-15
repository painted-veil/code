/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*暴力解法循环遍历，但是也不能完全通过
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0 ;i<nums.size();i++){
            count = 0;
            for(int j = i;j<nums.size(); j++){
                count =count+nums[j];
                result = result > count ? result : count;
            }
        }
        return result;
        */
       //贪心解法 O(n),O(1);
       int result = INT32_MIN;
       int count = 0;
       for(int i=0;i<nums.size();i++){//注意这里连续都是负数
           count =count + nums[i];
           if(count>result){
               result =count;
           }
           if(count <= 0 )
            count = 0;
       }
       return result;
    }
};
// @lc code=end

