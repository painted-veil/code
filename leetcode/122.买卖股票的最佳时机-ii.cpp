/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {//时间复杂度O(n)，空间复杂度O(1)
        int result = 0;
        for(int i=1; i<prices.size();i++){
            result+= max(prices[i]-prices[i-1],0);
        }
        return result;
    }
};
// @lc code=end

