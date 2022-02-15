/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public://贪心算法
    int maxProfit(vector<int>& prices) {//时间复杂度O(n),空间复杂度O(1)
        int low = INT_MAX;
        int result = 0;
        for(int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);   //取最左最小价格
            result = max(result, prices[i] - low); // 直接取最大区间利润
        }
        return result;
    }
};
// @lc code=end

