/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {//时间复杂度O(n),空间复杂度O(n);优化参考 斐波那契数列
        if(n<=1) return n;//下面从2开始操作 防止空指针
         vector<int> dp(n+1);
        dp[1] =1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }        
        return dp[n];
    }
};
// @lc code=end

