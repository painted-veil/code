/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <=1)
        return true;//如果只有一位数肯定是回文

        int left = 0;
        int right =s.length() -1;
        while(left < right){
            while(left< right && !isalnum(s[left]))//如果检验不是字母或数字则左指针右移
            left++;
            while(left < right && !isalnum(s[right]))
            right--;
            if(tolower(s[left]) != tolower(s[right]))//如果转为小写之后不能相等则无法构成回文
            return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

