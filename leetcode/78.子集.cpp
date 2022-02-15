/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,int startIndex){
        result.push_back(path);//收集子集，注意不要漏掉自身
        if(startIndex >= nums.size()){//终止条件可以不加
            return;
        }
        for(int i = startIndex; i < nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};
// @lc code=end

