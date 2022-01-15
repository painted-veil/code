/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x %10 ==0 && x!=0){
            return false;
        }
        int reversenumber = 0;
        while( x >reversenumber ){
            reversenumber = reversenumber*10 +x %10;
            x/=10;
        }
        return reversenumber ==x ||x ==reversenumber /10;//(长度为奇数可以通过reversenumber/10来去掉中位数)

    }
};
// @lc code=end

