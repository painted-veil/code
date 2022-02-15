/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
vector<vector<int>> result;
vector<int> path;//存放符合条件结果
public:
    void backtracking(int n,int k,int StartIndex) {
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i =StartIndex;i<=n;i++){
            path.push_back(i);
            backtracking(n,k,i+1);//递归
            path.pop_back();//回溯，撤销处理节点

        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};
// @lc code=end

