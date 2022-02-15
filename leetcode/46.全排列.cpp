/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,vector<bool>& used) {
        //找到一组
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;//path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
// @lc code=end

