/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex,vector<bool>& used){
        if (sum == target){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size() && sum +candidates[i] <=target;i++){
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if(i > 0&& candidates[i] == candidates[i-1]&&used[i-1]==false){
                continue;

            }
            sum = sum +candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates,target,sum,i+1,used);
            used[i] = false;
            sum = sum - candidates[i];
            path.pop_back();

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
        return result;

    }
};
// @lc code=end

