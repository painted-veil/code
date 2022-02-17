/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;;
        for(auto x :nums) hash.insert(x);//放入表中
        int res = 0;
        for(auto x : hash){
            if(!hash.count(x-1))//搜寻起始数字
            {
                int y =x;//以当前数x向后枚举
                while(hash.count(y+1)) y++;
                res = max(res,y-x+1);//更新答案
            }
        }
        return res;
    }
};
// @lc code=end

