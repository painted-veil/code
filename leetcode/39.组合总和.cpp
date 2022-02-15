/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;//时间复杂度O(n),空间复杂度O(n)
    vector<int> path;
    void backtracking(vector<int> &candidates,int target,int sum,int startindex){
        if(sum>target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = startindex; i<candidates.size();i++){
            sum +=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);
            sum = sum-candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return result;
    }
};
// @lc code=end

