/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1) return s;
        int start = 0;//记录回文子串的起始位置
        int end = 0;//记录最大回文子串的长度
        int maxlen = 0;//最大回文子串长度
        for(int i =0;i<len;i++) {
            int len1 = expendaroundcenter(s,i,i);//一个元素为中心
            int len2 = expendaroundcenter(s,i,i+1);//两个元素为中心
            maxlen = max(max(len1,len2),maxlen);
            if(maxlen > end - start +1){
                start = i - (maxlen - 1) / 2;
                end = i+maxlen / 2;
            }
        }
        return s.substr(start,maxlen);//从start开始长度为maxlen长度字符串

    }
    int expendaroundcenter(string &s,int left,int right)//记录以left和right为中心的回文串长度
    {
        int L = left;
        int R = right;
        while(L >=0 &&R<s.length() && s[R] == s[L]) {
            --L;
            ++R;
        }
        return R - L-1;
    }
};
// @lc code=end

