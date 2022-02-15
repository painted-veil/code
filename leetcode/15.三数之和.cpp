/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
      int len = nums.size();
      if(len < 3){
        return result;
      }
      sort(nums.begin(), nums.end());
        for(int i = 0; i < len;i++){
          if(nums[i] > 0) break;
          if(i > 0 && nums[i] == nums[i-1])  continue;//注意这里是i>0不是nums[i]>0
          int left = i+1;
          int right = len-1;
          while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                vector<int> temp ={nums[i],nums[left],nums[right]};
                result.push_back(temp);
                while(left < right && nums[left] == nums[left + 1]) ++left;
                while(left < right && nums[right] == nums[right - 1]) --right;
                --right;
                ++left;
            }
            else if(sum > 0){
                --right;
            }
            else if(sum < 0){
                ++left;
            }
          }
        }
        return result;
    }
};
// @lc code=end

