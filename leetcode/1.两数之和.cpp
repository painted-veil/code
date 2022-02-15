/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//时间O(n)，空间O(n)
    /*   for(int i=0; i<nums.size(); i++)
       {
           for(int j=i+1; j<nums.size(); j++)
           {
               if(nums[j]+nums[i] == target)
               {
                   return {i,j};
               }
           }
       }
    
        return {};
    }*/
    std::unordered_map<int,int> map;//注意这里不是set
    for(int i =0;i<nums.size();i++){
        auto iter = map.find(target - nums[i]);
        if(iter != map.end()){
            return {iter->second, i};
        }
            map.insert(pair<int, int>(nums[i], i));
    }
    return {};
    }
};
// @lc code=end

