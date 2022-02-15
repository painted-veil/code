/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans = 0;
        while(ans < 40){//剔除大于40的值
            int x = rand7();
            int y = rand7();
            ans = (x -1) * 7 + y;
        }
        return ans%10 +1;//构造1-10的的均匀分布

    }
};
// @lc code=end

